#!/bin/sh

USARTs="1 2 3 6"
UARTs="4 5 7 8"

cat << EOF
//
// Generated by ${0} on $(date)
//

#if ENABLE_UART_LISTENING

#define ASSIGN_IRQ_PORT(_irqn_, _p_) do { uart ## _irqn_ ## _port = (_p_); } while (0);

static void UARTx_RXNE_IRQHandler(uart_port_t *p) {
#if UART_INPUT_BUFFER_BYTES > 0
	if (p->rx_buf.bytes < UART_INPUT_BUFFER_BYTES) {
		p->rx_buf.buffer[p->rx_buf.bytes] = p->uartx->DR;
		++p->rx_buf.bytes;
	} else
#endif // UART_INPUT_BUFFER_BYTES > 0
	{
		// We still need to read the byte or else we'll just immediately re-enter
		// this interrupt
		uint8_t rx = p->uartx->DR;
		UNUSED(rx);
	}
	//
	// By doing this instead, we can tell if we missed anything by checking if bytes > UART_INPUT_BUFFER_BYTES
	//p->rx_buf.buffer[p->rx_buf.bytes % UART_INPUT_BUFFER_BYTES] = p->uartx->DR;
	//++p->rx_buf.bytes;

	//NVIC_DisableIRQ(p->irqn);
	NVIC_ClearPendingIRQ(p->irqn);

	return;
}

EOF

template="
//
// USARTnnn
//
#if HAVE_UARTnnn
static uart_port_t *uartnnn_port;
//__attribute__((weak))
void USARTnnn_IRQHandler(void) {
	if (BIT_IS_SET(uartnnn_port->uartx->SR, U_S_ART_SR_RXNE)) {
		UARTx_RXNE_IRQHandler(uartnnn_port);
		uart_rx_irq_hook(uartnnn_port);
	}

	return;
}
#endif // HAVE_UARTnnn
"

for u in ${USARTs}; do
	printf "%s" "${template}" | sed -e "s|nnn|${u}|g" -e "s|U_S_ART|USART|g"
done
for u in ${UARTs}; do
	printf "%s" "${template}" | sed -e "s|nnn|${u}|g" -e "s|USART|UART|g" -e "s|U_S_ART|USART|g"
done

cat << EOF

#else // ENABLE_UART_LISTENING
#define ASSIGN_IRQ_PORT(_irqn_, _p_) ((void )0U)

#endif // ENABLE_UART_LISTENING
EOF
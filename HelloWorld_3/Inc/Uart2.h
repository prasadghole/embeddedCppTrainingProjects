/*
 * Uart.h
 * Author: 20006401
 */

#ifndef INC_Uart2_H_
#define INC_Uart2_H_

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#include "stm32f7xx_hal.h"

namespace stm32f767 {

namespace Usart {

class Settings {
 public:
  Settings() {
    this->m_baudrate = 115200;
    this->m_bits = 8;
    this->m_parity = 0;
    this->m_stopbit = 1;
    this->m_flowcontrol = 0;

  }
  Settings(uint32_t baudrate, uint32_t bits, uint32_t parity, uint32_t stopbit,uint32_t mode,
           uint32_t flowcontrol)
      : m_baudrate(baudrate),
        m_bits(bits),
        m_parity(parity),
        m_stopbit(stopbit),
        m_mode(mode),
        m_flowcontrol(flowcontrol) {
  }

  uint32_t m_baudrate;
  uint32_t m_bits;
  uint32_t m_parity;
  uint32_t m_stopbit;
  uint32_t m_mode;
  uint32_t m_flowcontrol;
};

enum eParity {
  NONE,
  ODD,
  EVEN
};

class Uart2 {
 public:
  Uart2();
  Uart2(Settings & settings);

  bool Initialize();
  bool Transmit(const char  * buffer,const uint32_t len);
 private:
  UART_HandleTypeDef m_handle;
  Settings m_setting;
};

}
}
#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* INC_UART_H_ */

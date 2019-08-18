/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __usart_H
#define __usart_H

#ifdef __cplusplus
extern "C" {
#endif

#include "cstdint"

class Settings
      {
        public:
          Settings()
          {
            this->m_baudrate = 115200;
            this->m_bits = 8;
            this->m_parity = 0;
            this->m_stopbit = 1;
            this->m_flowcontrol = 0;

          }
          Settings(uint32_t baudrate, uint32_t bits, uint32_t parity,
              uint32_t stopbit, uint32_t mode, uint32_t flowcontrol) :
              m_baudrate(baudrate), m_bits(bits), m_parity(parity), m_stopbit(
                  stopbit), m_mode(mode), m_flowcontrol(flowcontrol)
          {
          }

          uint32_t m_baudrate;
          uint32_t m_bits;
          uint32_t m_parity;
          uint32_t m_stopbit;
          uint32_t m_mode;
          uint32_t m_flowcontrol;
      };
class IUsart {
 public:
  IUsart() {
  }
  virtual bool Initialize() = 0;
  virtual bool Transmit(const char * buffer, const uint32_t len) = 0;

};

#ifdef __cplusplus
}
#endif

#endif /*__ usart_H */


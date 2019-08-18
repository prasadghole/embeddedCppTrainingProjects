#ifndef __IGpio_H
#define __IGpio_H

#include "cstdint"
#include "stm32f7xx.h"

#ifdef __cplusplus
extern "C"
{
#endif

  namespace stm32f767
  {
    namespace gpio
    {
      class Settings
      {
        public:
          Settings()
          {
            this->m_Mode  = GPIO_MODE_OUTPUT_PP;
            this->m_Pull  = GPIO_PULLUP;
            this->m_Speed = GPIO_SPEED_FREQ_VERY_HIGH;

          }

          uint32_t m_Mode;

          uint32_t m_Pull;

          uint32_t m_Speed;

          uint32_t m_Alternate;
      };
      class IGpio
      {
        public:
          IGpio()
          {
          }
          virtual bool Initialize(uint16_t pin) = 0;
          virtual void Set(uint16_t pin) = 0;
          virtual void Clear(uint16_t pin) = 0;
          virtual void Toggle(uint16_t pin) = 0;

      };
    }
  }

#ifdef __cplusplus
}
#endif

#endif /*__IGpio_H */

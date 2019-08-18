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
            this->m_Alternate = 0u ; //ignored
          }

          Settings(uint32_t mode , uint32_t pull , uint32_t speed , uint32_t alternate) :
            m_Mode(mode),m_Pull(pull),m_Speed(speed),m_Alternate(alternate)
          {

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

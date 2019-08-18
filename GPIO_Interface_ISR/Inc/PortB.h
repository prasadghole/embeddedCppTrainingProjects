#ifndef __IGpioPortA_H
#define __IGpioPortA_H

#include "IGpio.h"
#include "cstdint"

#ifdef __cplusplus
extern "C"
{
#endif

#include <stm32f7xx_hal.h>

  namespace stm32f767
  {
    namespace gpio
    {
      class PortB: public IGpio
      {
        public:
          PortB() : m_member(GPIOB) , m_settings()
          {
          }
          virtual bool Initialize(uint16_t pin) override;
          virtual void Set(uint16_t pin) override;
          virtual void Clear(uint16_t pin) override;
          virtual void Toggle(uint16_t pin) override;
        private:
          GPIO_TypeDef * m_member;
          Settings m_settings;
      };
    }
  }

#ifdef __cplusplus
}
#endif

#endif /*__IGpioPortA_H */

#ifndef __IGpioPortC_H
#define __IGpioPortC_H

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
      class PortC: public IGpio
      {
        public:
          PortC() : m_member(GPIOC) , m_settings()
          {
          }

          PortC(Settings s)
          {
            this->m_member = GPIOC;
            this->m_settings = s;
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

inline bool stm32f767::gpio::PortC::Initialize(uint16_t pin)
{
  GPIO_InitTypeDef  GPIO_InitStruct;

   __HAL_RCC_GPIOC_CLK_ENABLE();


   GPIO_InitStruct.Mode  = this->m_settings.m_Mode;
   GPIO_InitStruct.Pull  = this->m_settings.m_Pull;
   GPIO_InitStruct.Speed = this->m_settings.m_Speed;

   GPIO_InitStruct.Pin = pin;
   HAL_GPIO_Init(this->m_member, &GPIO_InitStruct);
}

inline void stm32f767::gpio::PortC::Set(uint16_t pin)
{
}

inline void stm32f767::gpio::PortC::Clear(uint16_t pin)
{
}

inline void stm32f767::gpio::PortC::Toggle(uint16_t pin)
{
}

#endif

#endif /*__IGpioPortA_H */

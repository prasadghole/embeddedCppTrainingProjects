#include "PortB.h"

bool stm32f767::gpio::PortB::Initialize(uint16_t pin)
{
  GPIO_InitTypeDef  GPIO_InitStruct;

  __HAL_RCC_GPIOB_CLK_ENABLE();


  GPIO_InitStruct.Mode  = this->m_settings.m_Mode;
  GPIO_InitStruct.Pull  = this->m_settings.m_Pull;
  GPIO_InitStruct.Speed = this->m_settings.m_Speed;

  GPIO_InitStruct.Pin = pin;
  HAL_GPIO_Init(this->m_member, &GPIO_InitStruct);
}

void stm32f767::gpio::PortB::Set(uint16_t pin)
{
  HAL_GPIO_WritePin(this->m_member, pin, GPIO_PIN_SET);
}

void stm32f767::gpio::PortB::Clear(uint16_t pin)
{
  HAL_GPIO_WritePin(this->m_member, pin, GPIO_PIN_SET);
}

void stm32f767::gpio::PortB::Toggle(uint16_t pin)
{
  HAL_GPIO_TogglePin(this->m_member, pin);
}

#include <Uart3.h>

//Default ctor
//stm32f767::Usart::Uart3::Uart3()
stm32f767::Usart::Uart3::Uart3()
{
  this->m_handle.Instance = USART3;
  this->m_setting.m_baudrate = 9600;
  this->m_setting.m_bits = 7;
  this->m_setting.m_parity = 0;
  this->m_setting.m_stopbit = 1;
  this->m_setting.m_mode = UART_MODE_TX_RX;
  this->m_setting.m_flowcontrol = UART_HWCONTROL_NONE;
}

stm32f767::Usart::Uart3::Uart3(Settings& settings)
{

  this->m_handle.Instance = USART3;
  this->m_setting.m_baudrate = this->m_setting.m_baudrate;
  this->m_setting.m_bits = this->m_setting.m_bits;
  ;
  this->m_setting.m_parity = this->m_setting.m_parity;
  ;
  this->m_setting.m_stopbit = this->m_setting.m_stopbit;
  ;
  this->m_setting.m_mode = this->m_setting.m_mode;
  this->m_setting.m_flowcontrol = this->m_setting.m_flowcontrol;
}

bool stm32f767::Usart::Uart3::Initialize()
{
  bool retval = true;

  this->m_handle.Instance = this->m_handle.Instance;
  this->m_handle.Init.BaudRate = this->m_setting.m_baudrate;
  this->m_handle.Init.WordLength = this->m_setting.m_bits;
  this->m_handle.Init.StopBits = this->m_setting.m_stopbit;
  this->m_handle.Init.Parity = this->m_setting.m_parity;
  this->m_handle.Init.Mode = this->m_setting.m_mode;
  this->m_handle.Init.HwFlowCtl = this->m_setting.m_flowcontrol;
  this->m_handle.Init.OverSampling = UART_OVERSAMPLING_16;
  this->m_handle.Init.OneBitSampling = UART_ONE_BIT_SAMPLE_DISABLE;
  this->m_handle.AdvancedInit.AdvFeatureInit = UART_ADVFEATURE_NO_INIT;

  if (HAL_UART_Init(&this->m_handle) != HAL_OK)
  {
    retval = true;
  }

  return retval;
}

bool stm32f767::Usart::Uart3::Transmit(const char * buffer, const uint32_t len)
{
  if (HAL_UART_Transmit(&this->m_handle, (uint8_t*) buffer, len, 10 * len)
      == HAL_OK)
  {
    return true;
  }
  else
  {
    return false;
  }
}

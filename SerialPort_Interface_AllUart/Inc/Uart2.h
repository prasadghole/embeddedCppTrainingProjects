#ifndef INC_Uart2_H_
#define INC_Uart2_H_

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

#include "Iusart.h"
#include "stm32f7xx_hal.h"

  namespace stm32f767
  {

    namespace Usart
    {

      class Uart2: public IUsart
      {
        public:
          Uart2();
          Uart2(Settings & settings);

          virtual bool Initialize() override;
          virtual bool Transmit(const char * buffer, const uint32_t len)
              override;
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

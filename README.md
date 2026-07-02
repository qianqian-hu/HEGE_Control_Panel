# HEGE_Control_Panel

## 1. Overview

## 2. Hardware
|  GPIO / Expander Pin  |
|----------------|------|
| CAN TX         | TODO |
| CAN RX         | TODO |
| Forward Button | TODO |
| Backward Button| TODO |
| Left Button    | TODO |
| Right Button   | TODO |
| Speed + Button |      |
| Speed - Button |      |
| Mode 1         |      |
| Mode 2         |      |

-CAN bus: TODO kbit/s
-Physical inputs: 4 direction buttons, 2 speed buttons, 1 rotary encoder for MANUAL / AUTO mode selection
-CAN reception remains active in both MANUAL and AUTO mode.

## 3. System Function
AUTO_MODE
  │
  │ encoder selects MANUAL
  │
WAIT_MANUAL_CONFIRMATION
  │
  │ main system confirms manual control
  │
MANUAL_MODE
  │
  │ encoder selects AUTO
  │
AUTO_MODE

:CAN messages are always received; Physical input is always read, but physical input is only accepted in MANUAL_ACTIVE.

## 4. CAN Communication
   ### 4.1 Received CAN Messages
   不受到state maschine的控制，持续接收can 信号
   
   ### 4.2 Transmitted CAN Messages
   
   ### 4.3 CAN Timeout
## 5. UI Layout
## 6. Physical Inputs
## 7. Timing
## 8. Safety and Error Handling
## 9. Power Supply
## 10. Mechanical Design
## 11. Main Loop Structure
## 12. Software Structure
## 13. Testing
## 14. Notes

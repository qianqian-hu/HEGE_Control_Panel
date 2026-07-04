#pragma once

// ================================================================
// GPIO CONFIG - TODO
// ================================================================

#define CAN_TX_GPIO             -1
#define CAN_RX_GPIO             -1

#define BTN_FORWARD_GPIO        -1
#define BTN_BACKWARD_GPIO       -1
#define BTN_LEFT_GPIO           -1
#define BTN_RIGHT_GPIO          -1
#define BTN_SPEED_UP_GPIO       -1
#define BTN_SPEED_DOWN_GPIO     -1

#define MODE_1_GPIO             -1
#define MODE_2_GPIO             -1

// ================================================================
// CAN CONFIG
// ================================================================

#define CAN_BITRATE             500000

#define CAN_ID_STATUS_215       0x215
#define CAN_ID_SPEED_315        0x315
#define CAN_ID_AUTH_195         0x195
#define CAN_ID_CONTROL_295      0x295

// ================================================================
// PERIOD CONFIG
// ================================================================

#define PERIOD_295_MS           10
#define PERIOD_UI_UPDATE_MS     50
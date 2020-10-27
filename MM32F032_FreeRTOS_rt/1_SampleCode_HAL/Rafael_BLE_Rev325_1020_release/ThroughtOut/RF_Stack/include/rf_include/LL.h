/*******************************************************************
 *
 * File Name  : LL.H
 * Description:
 *
 *
 *
 *******************************************************************
 *
 *      Copyright (c) 2020, All Right Reserved
 *      Rafael Microelectronics Co. Ltd.
 *      Taiwan, R.O.C.
 *
 *******************************************************************/

#ifndef _BLE_LL_H_
#define _BLE_LL_H_

#include "knl_pblc.h"  //LEN_LL_CH_MAP

#define MAX_NUM_CONN_SLV_HDL                    1
#define MAX_NUM_CONN_MAS_HDL                    0
#define MAX_NUM_CONN_HDL                        MAX_NUM_CONN_MAS_HDL+MAX_NUM_CONN_SLV_HDL

//LL_CONN_ID_CONN_PARA                          0~(MAX_NUM_CONN_HDL-1)
//#define LL_CONN_ID_CONN_S_PARA                  MAX_NUM_CONN_MAS_HDL
#define LL_CONN_ID_ADV_PARA                     MAX_NUM_CONN_HDL
#define LL_CONN_ID_SCAN_PARA                    (MAX_NUM_CONN_HDL+1)
#define LL_CONN_ID_INIT_PARA                    (MAX_NUM_CONN_HDL+2)
#define LL_CONN_ID_MASTER_RSV                   MAX_NUM_CONN_MAS_HDL
#define LL_CONN_ID_SLAVE_RSV                    MAX_NUM_CONN_HDL

#define LL_PATCH_MIC_FAIL_2M_PHY
#ifdef LL_PATCH_MIC_FAIL_2M_PHY
#define LL_PATCH_MIC_FAIL_DATA_SIZE_LESS
#define LL_PATCH_MIC_FAIL_DATA_SIZE_PARTICULAR
#define LEN_LL_PATCH_MIC_FAIL_CONDITION     7                   //Could be modified by users (less than 8).
#endif

enum
{
    _TICK_BASE_125P00_ = 0U,
    _TICK_BASE_156P25_ = 1U
};
#define _TICK_BASE_                 _TICK_BASE_125P00_

#if _TICK_BASE_ ==  _TICK_BASE_125P00_
#define _TICK_BASE_MULTIPLIER_      4
#else   //(#if _TICK_BASE_ ==  _TICK_BASE_125P00_)
#define _TICK_BASE_MULTIPLIER_      5
#endif  //(#if _TICK_BASE_ ==  _TICK_BASE_125P00_)

#define LL_PATCH_CONN_UDATE_FAIL_DUE_TO_USER_DELAY
#define LL_PATCH_PHY_UPDATE_FAIL_DUE_TO_USER_DELAY
#define LL_PATCH_NO_EVENT_DUE_TO_LL_CONN_ID_NOT_MATCH
#define LL_PATCH_FOR_CONNECTIOM_COMPLETE_SEND_CONNECT_UPDATE_REQ
/*******************************************************************
 *      Primitive type to LL task
 *******************************************************************/
#define LL_E0                                   0xB0
#define MLL_HCI_NULL                            (LL_E0+0x00)
#define HCLL_DISCONNECT                         (LL_E0+0x01)    //OGF: Link Control, 0x01
#define HCLL_READ_REMOTE_VER_INFO               (LL_E0+0x02)    //OGF: Link Control, 0x01
#define HCLL_SET_EVENT_MASK                     (LL_E0+0x03)    //OGF: Controller & Baseband, 0x03
#define HCLL_RESET                              (LL_E0+0x04)    //OGF: Controller & Baseband, 0x03
#define HCLL_READ_TRANSMIT_PWR_LEVEL            (LL_E0+0x05)    //OGF: Controller & Baseband, 0x03
#define HCLL_SET_CTRLER_TO_HOST_FLOW_CTRL       (LL_E0+0x06)    //OGF: Controller & Baseband, 0x03
#define HCLL_HOST_BUFFER_SIZE                   (LL_E0+0x07)    //OGF: Controller & Baseband, 0x03
#define HCLL_HOST_NUM_OF_COMPLETED_PACKETS      (LL_E0+0x08)    //OGF: Controller & Baseband, 0x03
#define HCLL_SET_EVENT_MASK_PAGE_2              (LL_E0+0x09)    //OGF: Controller & Baseband, 0x03, Spec. 4.1
#define HCLL_READ_LE_HOST_SUPPORT               (LL_E0+0x0A)    //OGF: Controller & Baseband, 0x03
#define HCLL_WRITE_LE_HOST_SUPPORT              (LL_E0+0x0B)    //OGF: Controller & Baseband, 0x03
#define HCLL_READ_AUTHEN_PAYLOAD_TIMEOUT        (LL_E0+0x0C)    //OGF: Controller & Baseband, 0x03, Spec. 4.1
#define HCLL_WRITE_AUTHEN_PAYLOAD_TIMEOUT       (LL_E0+0x0D)    //OGF: Controller & Baseband, 0x03, Spec. 4.1
#define HCLL_READ_LOCAL_VER_INFO                (LL_E0+0x0E)    //OGF: Informational Parameters, 0x04
#define HCLL_READ_LOCAL_SUPPORTED_CMD           (LL_E0+0x0F)    //OGF: Informational Parameters, 0x04
#define HCLL_READ_LOCAL_SUPPORTED_FEAT          (LL_E0+0x10)    //OGF: Informational Parameters, 0x04
#define HCLL_READ_BUFFER_SIZE                   (LL_E0+0x11)    //OGF: Informational Parameters, 0x04
#define HCLL_READ_BD_ADDR                       (LL_E0+0x12)    //OGF: Informational Parameters, 0x04
#define HCLL_READ_RSSI                          (LL_E0+0x13)    //OGF: Status Parameters, 0x05
#define HCLL_LE_SET_EVENT_MASK                  (LL_E0+0x14)    //OGF: LE Controller, 0x08
#define HCLL_LE_READ_BUFFER_SIZE                (LL_E0+0x15)    //OGF: LE Controller, 0x08
#define HCLL_LE_READ_LOCAL_SUPPORTED_FEAT       (LL_E0+0x16)    //OGF: LE Controller, 0x08
#define HCLL_LE_SET_RANDOM_ADDRESS              (LL_E0+0x17)    //OGF: LE Controller, 0x08
#define HCLL_LE_SET_ADV_PARAM                   (LL_E0+0x18)    //OGF: LE Controller, 0x08
#define HCLL_LE_READ_ADV_CH_TX_PWR              (LL_E0+0x19)    //OGF: LE Controller, 0x08
#define HCLL_LE_SET_ADV_DATA                    (LL_E0+0x1A)    //OGF: LE Controller, 0x08
#define HCLL_LE_SET_SCAN_RESPONSE_DATA          (LL_E0+0x1B)    //OGF: LE Controller, 0x08
#define HCLL_LE_SET_ADVERTISE_ENABLE            (LL_E0+0x1C)    //OGF: LE Controller, 0x08
#define HCLL_LE_SET_SCAN_PARAM                  (LL_E0+0x1D)    //OGF: LE Controller, 0x08
#define HCLL_LE_SET_SCAN_ENABLE                 (LL_E0+0x1E)    //OGF: LE Controller, 0x08
#define HCLL_LE_CREATE_CONN                     (LL_E0+0x1F)    //OGF: LE Controller, 0x08
#define HCLL_LE_CREATE_CONN_CANCEL              (LL_E0+0x20)    //OGF: LE Controller, 0x08
#define HCLL_LE_READ_WHITE_LIST_SIZE            (LL_E0+0x21)    //OGF: LE Controller, 0x08
#define HCLL_LE_CLEAR_WHITE_LIST                (LL_E0+0x22)    //OGF: LE Controller, 0x08
#define HCLL_LE_ADD_DEVICE_TO_WHITE_LIST        (LL_E0+0x23)    //OGF: LE Controller, 0x08
#define HCLL_LE_RMV_DEVICE_FROM_WHITE_LIST      (LL_E0+0x24)    //OGF: LE Controller, 0x08
#define HCLL_LE_CONN_UPDATE                     (LL_E0+0x25)    //OGF: LE Controller, 0x08
#define HCLL_LE_SET_HOST_CH_CLASSIFICATION      (LL_E0+0x26)    //OGF: LE Controller, 0x08
#define HCLL_LE_READ_CH_MAP                     (LL_E0+0x27)    //OGF: LE Controller, 0x08
#define HCLL_LE_READ_REMOTE_USED_FEAT           (LL_E0+0x28)    //OGF: LE Controller, 0x08
#define HCLL_LE_ENCRYPT                         (LL_E0+0x29)    //OGF: LE Controller, 0x08
#define HCLL_LE_RAND                            (LL_E0+0x2A)    //OGF: LE Controller, 0x08
#define HCLL_LE_START_ENCRYPTION                (LL_E0+0x2B)    //OGF: LE Controller, 0x08
#define HCLL_LE_LONG_TERM_KEY_REQ_REPLY         (LL_E0+0x2C)    //OGF: LE Controller, 0x08
#define HCLL_LE_LONG_TERM_KEY_REQ_NEG_REPLY     (LL_E0+0x2D)    //OGF: LE Controller, 0x08
#define HCLL_LE_READ_SUPPORTED_STATES_          (LL_E0+0x2E)    //OGF: LE Controller, 0x08
#define HCLL_LE_RECEIVER_TEST                   (LL_E0+0x2F)    //OGF: LE Controller, 0x08
#define HCLL_LE_TRANSMITTER_TEST                (LL_E0+0x30)    //OGF: LE Controller, 0x08
#define HCLL_LE_TEST_END                        (LL_E0+0x31)    //OGF: LE Controller, 0x08
#define HCLL_LE_REMOTE_CONN_PARAM_REQ_REPLY     (LL_E0+0x32)    //OGF: LE Controller, 0x08, Spec. 4.1
#define HCLL_LE_REMOTE_CONN_PARAM_REQ_NEG_REPLY (LL_E0+0x33)    //OGF: LE Controller, 0x08, Spec. 4.1
#define LLHC_ERR_CODE_UNKNOWN_HCI_COMMAND       (LL_E0+0x34)    //OGF: LE Controller, 0x08, Spec. 4.1
#define LLHC_ERR_CODE_INVALID_LMP_PARAMETERS    (LL_E0+0x35)    //OGF: LE Controller, 0x08, Spec. 4.1
#define HCLL_LE_ACL_DATA_PKT                    (LL_E0+0x36)    //
#define LLHC_LE_CTRL_PKT                        (LL_E0+0x37)    //
#define HCLL_LE_CTRL_PKT                        (LL_E0+0x38)    //
#define MLL_LL_CHN_MAP_UPD                      (LL_E0+0x39)    //
#define MLL_LL_ENC_REQ                          (LL_E0+0x3A)    //
/* add PHY Update command support */
#define HCLL_LE_READ_PHY                        (LL_E0+0x3B)    //
#define HCLL_LE_SET_DEFAULT_PHY                 (LL_E0+0x3C)    //
#define HCLL_LE_SET_PHY                         (LL_E0+0x3D)    //
#define HCLL_LE_SET_DATA_LENGTH                 (LL_E0+0x3E)    //
#define MLL_LE_CTRL_PKT                         (LL_E0+0x3F)
#define HCLL_LE_ACL_DATA_PKT_EXTEND             (LL_E0+0x40)
#define LL_E0_END                               HCLL_LE_ACL_DATA_PKT_EXTEND

#if (0xFF < LL_E0_END)
#pragma message("Error!! Check definition LL_E0")
#endif

/*******************************************************************
 *      Primitive type to ENC task
 *******************************************************************/
#define EC_E0                                   0x50
#define MEC_HCI_NULL                            (EC_E0+0x00)
#define LLEC_LE_ENCRYPT                         (EC_E0+0x01)
#define LLEC_LE_RAND                            (EC_E0+0x02)
#define LLEC_LE_START_ENCRYPTION                (EC_E0+0x03)
#define LLEC_LE_LONG_TERM_KEY_REQ_REPLY         (EC_E0+0x04)
#define ECHC_LE_CTRL_PKT                        (EC_E0+0x05)
#define SMEC_LE_CODE_SMP_PAIRING_CONFIRM        (EC_E0+0x06)
#define SMEC_LE_CODE_SMP_PAIRING_RANDOM         (EC_E0+0x07)
#define SMEC_LE_SMP_KEY_GEN                     (EC_E0+0x08)
#ifdef LL_PATCH_MIC_FAIL_DATA_SIZE_LESS
#define LLEC_LE_CCM_MANUAL                      (EC_E0+0x09)
#endif
#define LEN_CRC_INIT                3                                                   //LL__013

//LL__014
#define LEN_ADVPKT_HEADER           2
#define LEN_ADV_PAYLOAD_MAX         (LEN_BD_ADDR+LEN_ADV_SCAN_DATA_MAX)
#define LEN_ADV_PKT_MAX             (LEN_ADVPKT_HEADER+LEN_ADV_PAYLOAD_MAX)


#define LEN_AES_KEY                                             16
#define LEN_SMP_RAND                                            8
#define LEN_SMP_EDIV                                            2
#define LEN_SMP_SKDM                                            8
#define LEN_SMP_IVM                                             4
#define LEN_SMP_SKDS                                            8
#define LEN_SMP_IVS                                             4
#define LEN_SMP_IRK                                             16
#define LEN_SMP_CSRK                                            16
#define LEN_SMP_PKTCNT                                          5

#define HCI_CMD_OGF_INVALID                                     0x00
#define MAX_OGF_INVALID_NO                                      1

#define HCI_CMD_OGF_DISCONNECT                                  0x06    //OGF: Link Control, 0x01
#define HCI_CMD_OGF_READ_REMOTE_VERSION_INFORMATION             0x1D    //OGF: Link Control, 0x01
#define MAX_OGF_LINK_CONTROL_NO                                 (2+1)   //1: HCI_CMD_OGF_INVALID

#define HCI_CMD_OGF_SET_EVENT_MASK                              0x01    //OGF: Controller & Baseband, 0x03
#define HCI_CMD_OGF_RESET                                       0x03    //OGF: Controller & Baseband, 0x03
#define HCI_CMD_OGF_READ_TRANSMIT_POWER_LEVEL                   0x2D    //OGF: Controller & Baseband, 0x03
#define HCI_CMD_OGF_SET_CONTROLLER_TO_HOST_FLOW_CONTROL         0x31    //OGF: Controller & Baseband, 0x03
#define HCI_CMD_OGF_HOST_BUFFER_SIZE                            0x33    //OGF: Controller & Baseband, 0x03
#define HCI_CMD_OGF_HOST_NUMBER_OF_COMPLETED_PACKETS            0x35    //OGF: Controller & Baseband, 0x03
#define HCI_CMD_OGF_SET_EVENT_MASK_PAGE_2                       0x63    //OGF: Controller & Baseband, 0x03, Spec. 4.1
#define HCI_CMD_OGF_READ_LE_HOST_SUPPORT                        0x6C    //OGF: Controller & Baseband, 0x03
#define HCI_CMD_OGF_WRITE_LE_HOST_SUPPORT                       0x6D    //OGF: Controller & Baseband, 0x03
#define HCI_CMD_OGF_READ_AUTHENTICATED_PAYLOAD_TIMEOUT          0x7B    //OGF: Controller & Baseband, 0x03, Spec. 4.1
#define HCI_CMD_OGF_WRITE_AUTHENTICATED_PAYLOAD_TIMEOUT         0x7C    //OGF: Controller & Baseband, 0x03, Spec. 4.1
#define MAX_OGF_CONTROLLER_BASEBAND_NO                          (11+1)  //1: HCI_CMD_OGF_INVALID

#define HCI_CMD_OGF_READ_LOCAL_VERSION_INFORMATION              0x01    //OGF: Informational Parameters, 0x04
#define HCI_CMD_OGF_READ_LOCAL_SUPPORTED_COMMANDS               0x02    //OGF: Informational Parameters, 0x04
#define HCI_CMD_OGF_READ_LOCAL_SUPPORTED_FEATURES               0x03    //OGF: Informational Parameters, 0x04
#define HCI_CMD_OGF_READ_BUFFER_SIZE                            0x05    //OGF: Informational Parameters, 0x04
#define HCI_CMD_OGF_READ_BD_ADDR                                0x09    //OGF: Informational Parameters, 0x04
#define MAX_OGF_INFORMATIONAL_PARAM_NO                          (5+1)   //1: HCI_CMD_OGF_INVALID

#define HCI_CMD_OGF_READ_RSSI                                   0x05    //OGF: Status Parameters, 0x05
#define MAX_OGF_STATUS_PARAM_NO                                 (1+1)   //1: HCI_CMD_OGF_INVALID

#define HCI_CMD_OGF_LE_SET_EVENT_MASK                           0x01    //OGF: LE Controller, 0x08
#define HCI_CMD_OGF_LE_READ_BUFFER_SIZE                         0x02    //OGF: LE Controller, 0x08
#define HCI_CMD_OGF_LE_READ_LOCAL_SUPPORTED_FEATURES            0x03    //OGF: LE Controller, 0x08
#define HCI_CMD_OGF_LE_SET_RANDOM_ADDRESS                       0x05    //OGF: LE Controller, 0x08
#define HCI_CMD_OGF_LE_SET_ADVERTISING_PARAMETERS               0x06    //OGF: LE Controller, 0x08
#define HCI_CMD_OGF_LE_READ_ADVERTISING_CHANNEL_TX_POWER        0x07    //OGF: LE Controller, 0x08
#define HCI_CMD_OGF_LE_SET_ADVERTISING_DATA                     0x08    //OGF: LE Controller, 0x08
#define HCI_CMD_OGF_LE_SET_SCAN_RESPONSE_DATA                   0x09    //OGF: LE Controller, 0x08
#define HCI_CMD_OGF_LE_SET_ADVERTISE_ENABLE                     0x0A    //OGF: LE Controller, 0x08
#define HCI_CMD_OGF_LE_SET_SCAN_PARAMETERS                      0x0B    //OGF: LE Controller, 0x08
#define HCI_CMD_OGF_LE_SET_SCAN_ENABLE                          0x0C    //OGF: LE Controller, 0x08
#define HCI_CMD_OGF_LE_CREATE_CONNECTION                        0x0D    //OGF: LE Controller, 0x08
#define HCI_CMD_OGF_LE_CREATE_CONNECTION_CANCEL                 0x0E    //OGF: LE Controller, 0x08
#define HCI_CMD_OGF_LE_READ_WHITE_LIST_SIZE                     0x0F    //OGF: LE Controller, 0x08
#define HCI_CMD_OGF_LE_CLEAR_WHITE_LIST                         0x10    //OGF: LE Controller, 0x08
#define HCI_CMD_OGF_LE_ADD_DEVICE_TO_WHITE_LIST                 0x11    //OGF: LE Controller, 0x08
#define HCI_CMD_OGF_LE_REMOVE_DEVICE_FROM_WHITE_LIST_           0x12    //OGF: LE Controller, 0x08
#define HCI_CMD_OGF_LE_CONNECTION_UPDATE                        0x13    //OGF: LE Controller, 0x08
#define HCI_CMD_OGF_LE_SET_HOST_CHANNEL_CLASSIFICATION          0x14    //OGF: LE Controller, 0x08
#define HCI_CMD_OGF_LE_READ_CHANNEL_MAP                         0x15    //OGF: LE Controller, 0x08
#define HCI_CMD_OGF_LE_READ_REMOTE_USED_FEATURES                0x16    //OGF: LE Controller, 0x08
#define HCI_CMD_OGF_LE_ENCRYPT                                  0x17    //OGF: LE Controller, 0x08
#define HCI_CMD_OGF_LE_RAND                                     0x18    //OGF: LE Controller, 0x08
#define HCI_CMD_OGF_LE_START_ENCRYPTION                         0x19    //OGF: LE Controller, 0x08
#define HCI_CMD_OGF_LE_LONG_TERM_KEY_REQUEST_REPLY              0x1A    //OGF: LE Controller, 0x08
#define HCI_CMD_OGF_LE_LONG_TERM_KEY_REQUEST_NEGATIVE_REPLY     0x1B    //OGF: LE Controller, 0x08
#define HCI_CMD_OGF_LE_READ_SUPPORTED_STATES_                   0x1C    //OGF: LE Controller, 0x08
#define HCI_CMD_OGF_LE_RECEIVER_TEST                            0x1D    //OGF: LE Controller, 0x08
#define HCI_CMD_OGF_LE_TRANSMITTER_TEST                         0x1E    //OGF: LE Controller, 0x08
#define HCI_CMD_OGF_LE_TEST_END                                 0x1F    //OGF: LE Controller, 0x08
#define HCI_CMD_OGF_LE_REMOTE_CONN_PARAM_REQUEST_REPLY          0x20    //OGF: LE Controller, 0x08, Spec. 4.1
#define HCI_CMD_OGF_LE_REMOTE_CONN_PARAM_REQUEST_NEG_REPLY      0x21    //OGF: LE Controller, 0x08, Spec. 4.1
#define HCI_CMD_OGF_LE_SET_DATA_LENGTH                          0x22    //OGF: LE Controller, 0x08, Spec. 4.2
#define HCI_CMD_OGF_LE_READ_SUGGESTED_DEFAULT_DATA_LENGTH       0x23    //OGF: LE Controller, 0x08, Spec. 4.2
#define HCI_CMD_OGF_LE_WRITE_SUGGESTED_DEFAULT_DATA_LENGTH      0x24    //OGF: LE Controller, 0x08, Spec. 4.2
#define HCI_CMD_OGF_LE_READ_LOCAL_P256_PUBLIC_KEY               0x25    //OGF: LE Controller, 0x08, Spec. 4.2, optional
#define HCI_CMD_OGF_LE_GENERATE_DHKEY                           0x26    //OGF: LE Controller, 0x08, Spec. 4.2, optional
#define HCI_CMD_OGF_LE_ADD_DEVICE_TO_RESOLVING_LIST             0x27    //OGF: LE Controller, 0x08, Spec. 4.2
#define HCI_CMD_OGF_LE_REMOVE_DEVICE_FROM_RESOLVING_LIST        0x28    //OGF: LE Controller, 0x08, Spec. 4.2
#define HCI_CMD_OGF_LE_CLEAR_RESOLVING_LIST                     0x29    //OGF: LE Controller, 0x08, Spec. 4.2
#define HCI_CMD_OGF_LE_READ_RESOLVING_LIST_SIZE                 0x2A    //OGF: LE Controller, 0x08, Spec. 4.2
#define HCI_CMD_OGF_LE_READ_PEER_RESOLVABLE_ADDRESS             0x2B    //OGF: LE Controller, 0x08, Spec. 4.2
#define HCI_CMD_OGF_LE_READ_LOCAL_RESOLVABLE_ADDRESS            0x2C    //OGF: LE Controller, 0x08, Spec. 4.2
#define HCI_CMD_OGF_LE_SET_ADDRESS_RESOLUTION_ENABLE            0x2D    //OGF: LE Controller, 0x08, Spec. 4.2
#define HCI_CMD_OGF_LE_SET_RESOLVABLE_PRIVATE_ADDRESS_TIMEOUT   0x2E    //OGF: LE Controller, 0x08, Spec. 4.2
#define HCI_CMD_OGF_LE_READ_MAXIMUM_DATA_LENGTH                 0x2F    //OGF: LE Controller, 0x08, Spec. 4.2
#define HCI_CMD_OGF_LE_READ_PHY                                 0x30    //OGF: LE Controller, 0x08, Spec. 5.0
#define HCI_CMD_OGF_LE_SET_DEFAULT_PHY                          0x31    //OGF: LE Controller, 0x08, Spec. 5.0
#define HCI_CMD_OGF_LE_SET_PHY                                  0x32    //OGF: LE Controller, 0x08, Spec. 5.0

#define MAX_OGF_LE_CONTROLLER_NO                                (36+1)  //1: HCI_CMD_OGF_INVALID, 4.1 / 5.0



#define LL_TMR_S0                               0x00
#define LL_TMR_S1                               (LL_TMR_S0 + 1)
#define LL_TMR_S2                               (LL_TMR_S0 + 2)
#define LL_TMR_S3                               (LL_TMR_S0 + 3)
#define LL_TMR_S255                             (LL_TMR_S0 + 255)

#define LL_INT_S0                               0x00
#define LL_INT_S10                              (LL_INT_S0 + 10)
#define LL_INT_S11                              (LL_INT_S0 + 11)
#define LL_INT_S12                              (LL_INT_S0 + 12)
#define LL_INT_S13                              (LL_INT_S0 + 13)
#define LL_INT_S14                              (LL_INT_S0 + 14)
#define LL_INT_S15                              (LL_INT_S0 + 15)

#define LL_INT_S20                              (LL_INT_S0 + 20)
#define LL_INT_S21                              (LL_INT_S0 + 21)
#define LL_INT_S22                              (LL_INT_S0 + 22)
#define LL_INT_S23                              (LL_INT_S0 + 23)
#define LL_INT_S24                              (LL_INT_S0 + 24)

#define LL_INT_S30                              (LL_INT_S0 + 30)
#define LL_INT_S31                              (LL_INT_S0 + 31)
#define LL_INT_S32                              (LL_INT_S0 + 32)
#define LL_INT_S33                              (LL_INT_S0 + 33)

#define LL_INT_S40                              (LL_INT_S0 + 40)
#define LL_INT_S41                              (LL_INT_S0 + 41)
#define LL_INT_S42                              (LL_INT_S0 + 42)
#define LL_INT_S43                              (LL_INT_S0 + 43)
#define LL_INT_S44                              (LL_INT_S0 + 44)
#define LL_INT_S45                              (LL_INT_S0 + 45)

#define LL_INT_S50                              (LL_INT_S0 + 50)
#define LL_INT_S51                              (LL_INT_S0 + 51)
#define LL_INT_S52                              (LL_INT_S0 + 52)
#define LL_INT_S53                              (LL_INT_S0 + 53)
#define LL_INT_S54                              (LL_INT_S0 + 54)
#define LL_INT_S55                              (LL_INT_S0 + 55)

//#define LL_TMR_TICKS_RSV_WAKEUP                 5   //by user
extern uint8_t LL_Tmr_Ticks_RSV_Wakeup;


#define LL_TMR_TICKS_RSV_RF_INIT                2   //by user
#define LL_TMR_TICKS_RSV_BASE                   2   //by user

#define SIZE_WHITE_LIST_ENTRIES                 4
#define MAX_TBLK_LL_NO                          (2*(MAX_NUM_CONN_HDL+1))    //1: reserved for Flash control
#define DEF_EMPTY_WHITE_LIST                    0xFC

#define NUM_LL_ADV_CH                           3                           //LL__017
#define NUM_LL_DATA_CH                          37                          //LL__017

#define NUM_LL_CONN_FAIL_ESTB                   6                           //LL__029

//LL__018
#define LL_FEATURE_LE_ENCRYPTION                0x01
#define LL_FEATURE_CONN_PARAM_REQ_PROC          0x02
#define LL_FEATURE_EXTND_REJ_IND                0x04
#define LL_FEATURE_SLV_INIT_FEAT_EXCHANGE       0x08
#define LL_FEATURE_LE_PING                      0x10
#define LL_FEATURE_LE_DATA_PKT_LENGTH_EXTN      0x20
#define LL_FEATURE_LL_PRIVACY                   0x40
#define LL_FEATURE_EXTND_SCN_FILTER_POLICIES    0x80
#define LL_FEATURE_LE_2M_PHY                    0x01
#define LL_FEATURE_STABLE_MOD_INDEX_TRMT        0x02
#define LL_FEATURE_STABLE_MOD_INDEX_RCV         0x04
#define LL_FEATURE_LE_CODED_PHY                 0x08
#define LL_FEATURE_LE_EXTND_ADV                 0x10
#define LL_FEATURE_LE_PRDC_ADV                  0x20
#define LL_FEATURE_CHN_SEL_ALGORITHM_2          0x40
#define LL_FEATURE_LE_POWER_CLASS_1             0x80
#define LL_FEATURE_MIN_NUM_USED_CHN_PROCEDURE   0x01
#define LL_FEATURE_CONN_CTE_REQUEST                         0x02
#define LL_FEATURE_CONN_CTE_RESPONSE                        0x04
#define LL_FEATURE_CONN_LESS_CTE_TRANSMITTER                0x08
#define LL_FEATURE_CONN_LESS_CTE_RECEIVER                   0x10
#define LL_FEATURE_ANTENNA_SWITCHING_DURING_CTE_TRANS_AOD   0x20
#define LL_FEATURE_ANTENNA_SWITCHING_DURING_CTE_RECEPT_AOA  0x40
#define LL_FEATURE_RECEIVING_CONSTANT_TONE_EXTENSIONS       0x80
#define LL_FEATURE_PERIODIC_ADV_SYNC_TRANSFER_SENDER        0x01
#define LL_FEATURE_PERIODIC_ADV_SYNC_TRANSFER_RECIPIENT     0x02
#define LL_FEATURE_SLEEP_CLOCK_ACCURACY_UPDATES             0x04
#define LL_FEATURE_REMOTE_PUBLIC_KEY_VALIDATION             0x08


#define LL_VERSION_VERSNR                       BLE_VERSION
#define LL_VERSION_COMPID_L                     BLE_COMPANY_ID_L
#define LL_VERSION_COMPID_H                     BLE_COMPANY_ID_H
#define LL_VERSION_SUBVERSNR_L                  0x00
#define LL_VERSION_SUBVERSNR_H                  0x00
#define NUM_LL_VERSION                          5

#define LL_ADV_FLTR_POLICY_NOT_USED             0x00                        //LL__022
#define LL_ADV_FLTR_POLICY_SCAN_WHT_LST         0x01                        //LL__022
#define LL_ADV_FLTR_POLICY_CONN_WHT_LST         0x02                        //LL__022
#define LL_ADV_FLTR_POLICY_SCAN_CONN_WHT_LST    0x03                        //LL__022
#define LL_SCN_FLTR_POLICY_NOT_USED             0x00                        //HCI__027
#define LL_SCN_FLTR_POLICY_WHT_LST              0x01                        //HCI__027
#define LL_INIT_FLTR_POLICY_NOT_USED            0x00                        //LL__003
#define LL_INIT_FLTR_POLICY_WHT_LST             0x01                        //LL__003

//LL__020
#define LE_LL_SCA_500PPM    0
#define LE_LL_SCA_250PPM    1
#define LE_LL_SCA_150PPM    2
#define LE_LL_SCA_100PPM    3
#define LE_LL_SCA_075PPM    4
#define LE_LL_SCA_050PPM    5
#define LE_LL_SCA_030PPM    6
#define LE_LL_SCA_020PPM    7
#define LE_LL_SCA           LE_LL_SCA_500PPM

//LL__021
#define LE_ADV_TYPE_ADV_IND             0x00 // undirected,connectable
#define LE_ADV_TYPE_ADV_DIRECT_IND      0x01 // directed  ,connecetable
#define LE_ADV_TYPE_ADV_NONCONN_IND     0x02 // undirected,non-scannable,non-connectable
#define LE_ADV_TYPE_SCAN_REQ            0x03
#define LE_ADV_TYPE_SCAN_RSP            0x04
#define LE_ADV_TYPE_CONNECT_REQ         0x05
#define LE_ADV_TYPE_ADV_SCAN_IND        0x06 // scannable, undirected
#define LE_ADV_TYPE_RESERVED            0x07

#define FLD_MSK_LL_ADV_TXADDR_TYPE      0x40
#define FLD_MSK_LL_ADV_RXADDR_TYPE      0x80
#define FLD_MSK_LL_ADV_TYPE             0x0F
#define FLD_MSK_LL_ADV_LEN              0x3F

#define FLD_MSK_LL_DATA_LLID            0x03
#define FLD_MSK_LL_DATA_NESN            0x04
#define FLD_MSK_LL_DATA_SN              0x08
#define FLD_MSK_LL_DATA_MD              0x10
#define FLD_MSK_LL_DATA_RSV             0xE0
#define FLD_MSK_LL_DATA_LEN             0xFF

#define LL_DATA_LLID_RESERVE            0x00
#define LL_DATA_LLID_EMPTY_CONTI        0x01
#define LL_DATA_LLID_START_COMPLETE     0x02
#define LL_DATA_LLID_CONTROL            0x03

#define LL_CONN_UPDATE_REQ              0x00
#define LL_CHANNEL_MAP_REQ              0x01
#define LL_TERMINATE_IND                0x02
#define LL_ENC_REQ                      0x03
#define LL_ENC_RSP                      0x04
#define LL_START_ENC_REQ                0x05
#define LL_START_ENC_RSP                0x06
#define LL_UNKNOWN_RSP                  0x07
#define LL_FEATURE_REQ                  0x08
#define LL_FEATURE_RSP                  0x09
#define LL_PAUSE_ENC_REQ                0x0A
#define LL_PAUSE_ENC_RSP                0x0B
#define LL_VERSION_IND                  0x0C
#define LL_REJECT_IND                   0x0D
#define LL_SLAVE_FEATURE_REQ            0x0E
#define LL_CONNECTION_PARAM_REQ         0x0F
#define LL_CONNECTION_PARAM_RSP         0x10
#define LL_REJECT_IND_EXT               0x11
#define LL_PING_REQ                     0x12
#define LL_PING_RSP                     0x13
#define LL_LENGTH_REQ                   0x14
#define LL_LENGTH_RSP                   0x15
#define LL_PHY_REQ                      0x16
#define LL_PHY_RSP                      0x17
#define LL_PHY_UPDATE_IND               0x18
#define LL_MIN_USED_CHANNELS_IND        0x19
#define LL_MAX_CTRL_OP                  LL_MIN_USED_CHANNELS_IND
#define LL_RSV_CTRL_OP                  (LL_MAX_CTRL_OP+1)

#define LL_TX_PHYS_1M_PHY               0x01
#define LL_TX_PHYS_2M_PHY               0x02
#define LL_TX_PHYS_CODED_PHY            0x04
#define LL_TX_PHYS_RESERVED             0xF8
#define LL_TX_PHYS_DEFAULT              LL_TX_PHYS_1M_PHY
#define LL_RX_PHYS_1M_PHY               0x01
#define LL_RX_PHYS_2M_PHY               0x02
#define LL_RX_PHYS_CODED_PHY            0x04
#define LL_RX_PHYS_RESERVED             0xF8
#define LL_RX_PHYS_DEFAULT              LL_RX_PHYS_1M_PHY
#define LL_RX_PHYS_TX_NO_SUPPORT        (0|LL_TX_PHYS_CODED_PHY|LL_TX_PHYS_RESERVED)
#define LL_RX_PHYS_RX_NO_SUPPORT        (0|LL_RX_PHYS_CODED_PHY|LL_RX_PHYS_RESERVED)    //symmetric, ==LL_RX_PHYS_TX_NO_SUPPORT

#define LL_PHY_OPTIONS_CODED_PHY_PREPER_NONE    0x00
#define LL_PHY_OPTIONS_CODED_PHY_PREPER_S2      0x01
#define LL_PHY_OPTIONS_CODED_PHY_PREPER_S8      0x02
#define LL_PHY_OPTIONS_CODED_PHY_PREPER_MSK     0x03

#define LL_ALL_PHYS_PREFER_TX_Y_RX_Y    0x00
#define LL_ALL_PHYS_PREFER_TX_N_RX_Y    0x01
#define LL_ALL_PHYS_PREFER_TX_Y_RX_N    0x02
#define LL_ALL_PHYS_PREFER_TX_N_RX_N    (LL_ALL_PHYS_PREFER_TX_N_RX_Y|LL_ALL_PHYS_PREFER_TX_Y_RX_N)


#define LL_CONN_ID_NORMAL                       0x00                                        //LL__026, LL__027
#define LL_CONN_ID_STBY                         0x01                                        //LL__026, LL__027
#define LL_CONN_ID_ADV                          0x02                                        //LL__026, LL__027
#define LL_CONN_ID_INIT                         0x03                                        //LL__026, LL__027
#define LL_CONN_ID_CONN                         0x04                                        //LL__026, LL__027
#define LL_CONN_ID_LL_TERM_WAIT                 0x05
#define LL_CONN_ID_LL_CONN_UPD                  0x06
#define LL_CONN_ID_LL_MSK_RCVD                  0x80
#define LL_CONN_ID_LL_CONN_UPD_REQ_RCVD         (LL_CONN_ID_LL_MSK_RCVD|LL_CONN_UPDATE_REQ)
#define LL_CONN_ID_LL_CHN_MAP_REQ_RCVD          (LL_CONN_ID_LL_MSK_RCVD|LL_CHANNEL_MAP_REQ)
#define LL_CONN_ID_LL_TERM_IND_RCVD             (LL_CONN_ID_LL_MSK_RCVD|LL_TERMINATE_IND)
//#define LL_CONN_ID_LL_ENC_REQ_RCVD              (LL_CONN_ID_LL_MSK_RCVD|LL_ENC_REQ)
//#define LL_CONN_ID_LL_ENC_RSP_RCVD              (LL_CONN_ID_LL_MSK_RCVD|LL_ENC_RSP)
//#define LL_CONN_ID_LL_START_ENC_REQ_RCVD        (LL_CONN_ID_LL_MSK_RCVD|LL_START_ENC_REQ)
//#define LL_CONN_ID_LL_START_ENC_RSP_RCVD        (LL_CONN_ID_LL_MSK_RCVD|LL_START_ENC_RSP)
//#define LL_CONN_ID_LL_UNKNOWN_RSP_RCVD          (LL_CONN_ID_LL_MSK_RCVD|LL_UNKNOWN_RSP)
//#define LL_CONN_ID_LL_FEAT_REQ_RCVD             (LL_CONN_ID_LL_MSK_RCVD|LL_FEATURE_REQ)
//#define LL_CONN_ID_LL_FEAT_RSP_RCVD             (LL_CONN_ID_LL_MSK_RCVD|LL_FEATURE_RSP)
//#define LL_CONN_ID_LL_PAUSE_ENC_REQ_RCVD        (LL_CONN_ID_LL_MSK_RCVD|LL_PAUSE_ENC_REQ)
//#define LL_CONN_ID_LL_PAUSE_ENC_RSP_RCVD        (LL_CONN_ID_LL_MSK_RCVD|LL_PAUSE_ENC_RSP)
#define LL_CONN_ID_LL_VERSION_IND_RCVD          (LL_CONN_ID_LL_MSK_RCVD|LL_VERSION_IND)
//#define LL_CONN_ID_LL_REJECT_IND_RCVD           (LL_CONN_ID_LL_MSK_RCVD|LL_REJECT_IND)
#define LL_CONN_ID_LL_SLAVE_FEATURE_REQ_RCVD    (LL_CONN_ID_LL_MSK_RCVD|LL_SLAVE_FEATURE_REQ)
#define LL_CONN_ID_LL_CONNECTION_PARAM_REQ_RCVD (LL_CONN_ID_LL_MSK_RCVD|LL_CONNECTION_PARAM_REQ)
#define LL_CONN_ID_LL_CONNECTION_PARAM_RSP_RCVD (LL_CONN_ID_LL_MSK_RCVD|LL_CONNECTION_PARAM_RSP)
#define LL_CONN_ID_LL_REJECT_IND_EXT_RCVD       (LL_CONN_ID_LL_MSK_RCVD|LL_REJECT_IND_EXT)
#define LL_CONN_ID_LL_PING_REQ_RCVD             (LL_CONN_ID_LL_MSK_RCVD|LL_PING_REQ)
#define LL_CONN_ID_LL_PING_RSP_RCVD             (LL_CONN_ID_LL_MSK_RCVD|LL_PING_RSP)
//#define LL_CONN_ID_LL_LENGTH_REQ_RCVD           (LL_CONN_ID_LL_MSK_RCVD|LL_LENGTH_REQ)
//#define LL_CONN_ID_LL_LENGTH_RSP_RCVD           (LL_CONN_ID_LL_MSK_RCVD|LL_LENGTH_RSP)
//#define LL_CONN_ID_LL_PHY_REQ_RCVD              (LL_CONN_ID_LL_MSK_RCVD|LL_PHY_REQ)
//#define LL_CONN_ID_LL_PHY_RSP_RCVD              (LL_CONN_ID_LL_MSK_RCVD|LL_PHY_RSP)
#define LL_CONN_ID_LL_PHY_UPDATE_IND_RCVD       (LL_CONN_ID_LL_MSK_RCVD|LL_PHY_UPDATE_IND)
//#define LL_CONN_ID_LL_MIN_USED_CHANNELS_IND_RCVD (LL_CONN_ID_LL_MSK_RCVD|LL_MIN_USED_CHANNELS_IND)

#define LL_CONN_ID_LL_MSK_INIT                  0x40
#define LL_CONN_ID_LL_CONN_UPD_REQ              (LL_CONN_ID_LL_MSK_INIT|LL_CONN_UPDATE_REQ)
#define LL_CONN_ID_LL_CHN_MAP_REQ               (LL_CONN_ID_LL_MSK_INIT|LL_CHANNEL_MAP_REQ)
#define LL_CONN_ID_LL_TERM_IND                  (LL_CONN_ID_LL_MSK_INIT|LL_TERMINATE_IND)
#define LL_CONN_ID_LL_ENC_REQ                   (LL_CONN_ID_LL_MSK_INIT|LL_ENC_REQ)
#define LL_CONN_ID_LL_ENC_RSP                   (LL_CONN_ID_LL_MSK_INIT|LL_ENC_RSP)
#define LL_CONN_ID_LL_START_ENC_REQ             (LL_CONN_ID_LL_MSK_INIT|LL_START_ENC_REQ)
#define LL_CONN_ID_LL_START_ENC_RSP             (LL_CONN_ID_LL_MSK_INIT|LL_START_ENC_RSP)
#define LL_CONN_ID_LL_UNKNOWN_RSP               (LL_CONN_ID_LL_MSK_INIT|LL_UNKNOWN_RSP)
#define LL_CONN_ID_LL_FEAT_REQ                  (LL_CONN_ID_LL_MSK_INIT|LL_FEATURE_REQ)
#define LL_CONN_ID_LL_FEAT_RSP                  (LL_CONN_ID_LL_MSK_INIT|LL_FEATURE_RSP)
#define LL_CONN_ID_LL_PAUSE_ENC_REQ             (LL_CONN_ID_LL_MSK_INIT|LL_PAUSE_ENC_REQ)
#define LL_CONN_ID_LL_PAUSE_ENC_RSP             (LL_CONN_ID_LL_MSK_INIT|LL_PAUSE_ENC_RSP)
#define LL_CONN_ID_LL_VERSION_IND               (LL_CONN_ID_LL_MSK_INIT|LL_VERSION_IND)
#define LL_CONN_ID_LL_REJECT_IND                (LL_CONN_ID_LL_MSK_INIT|LL_REJECT_IND)
#define LL_CONN_ID_LL_SLAVE_FEATURE_REQ         (LL_CONN_ID_LL_MSK_INIT|LL_SLAVE_FEATURE_REQ)
#define LL_CONN_ID_LL_CONNECTION_PARAM_REQ      (LL_CONN_ID_LL_MSK_INIT|LL_CONNECTION_PARAM_REQ)
#define LL_CONN_ID_LL_CONNECTION_PARAM_RSP      (LL_CONN_ID_LL_MSK_INIT|LL_CONNECTION_PARAM_RSP)
#define LL_CONN_ID_LL_REJECT_IND_EXT            (LL_CONN_ID_LL_MSK_INIT|LL_REJECT_IND_EXT)
#define LL_CONN_ID_LL_PING_REQ                  (LL_CONN_ID_LL_MSK_INIT|LL_PING_REQ)
#define LL_CONN_ID_LL_PING_RSP                  (LL_CONN_ID_LL_MSK_INIT|LL_PING_RSP)
#define LL_CONN_ID_LL_LENGTH_REQ                (LL_CONN_ID_LL_MSK_INIT|LL_LENGTH_REQ)
//#define LL_CONN_ID_LL_LENGTH_RSP                (LL_CONN_ID_LL_MSK_INIT|LL_LENGTH_RSP)
#define LL_CONN_ID_LL_PHY_REQ                   (LL_CONN_ID_LL_MSK_INIT|LL_PHY_REQ)
#define LL_CONN_ID_LL_PHY_RSP                   (LL_CONN_ID_LL_MSK_INIT|LL_PHY_RSP)
#define LL_CONN_ID_LL_PHY_UPDATE_IND            (LL_CONN_ID_LL_MSK_INIT|LL_PHY_UPDATE_IND)
//#define LL_CONN_ID_LL_MIN_USED_CHANNELS_IND     (LL_CONN_ID_LL_MSK_INIT|LL_MIN_USED_CHANNELS_IND)

#define LL_CONN_ID_RSV                          0xFF

#define LL_CONN_ID_HDL_H                        0x01                        //LL__026, HCI__007

#define LL_SMP_GATE_OFF                         0
#define LL_SMP_GATE_ENC_WAIT                    1
#define LL_SMP_GATE_ENC_PAUSE                   2

#define LL_SMP_DATA_CH_R_T_NORMAL               0
#define LL_SMP_DATA_CH_T_CCM                    0x01
#define LL_SMP_DATA_CH_R_CCM                    0x02
#define LL_SMP_DATA_CH_MASTER                   0x08
#define LL_SMP_DATA_CH_R_T_CCM                  (LL_SMP_DATA_CH_T_CCM|LL_SMP_DATA_CH_R_CCM)
#define LL_SMP_DATA_CH_MSK                      (LL_SMP_DATA_CH_T_CCM|LL_SMP_DATA_CH_R_CCM)

#define MSK_LL_SMP_DATA_CH_MASTER               0x80

#define LL_ACK_FLOW_NESN_0              0
#define LL_ACK_FLOW_NESN_1              FLD_MSK_LL_DATA_SN
#define LL_ACK_FLOW_NESN_2              FLD_MSK_LL_DATA_NESN
#define LL_ACK_FLOW_NESN_3              (FLD_MSK_LL_DATA_SN|FLD_MSK_LL_DATA_NESN)

//Below reference to FLD_MSK_LL_DATA_RSV
#define LL_ACK_TX_NEW_N_EPT             0x20    //Ack w. Not empty LL_data packet
#define LL_PKT_TX_EI                    0x40    //End for integrated.

#define LL_ACK_RX_NEW                   0x40
#define LL_ACK_TX_NEW                   0x80

#define LL_ACK_TO_RO                    0x00
#define LL_ACK_TO_RN                    LL_ACK_RX_NEW
#define LL_ACK_TN_RO                    LL_ACK_TX_NEW
#define LL_ACK_TN_RN                    (LL_ACK_TX_NEW|LL_ACK_RX_NEW)

#define FLD_LL_SCN_REQ_BGN_SCN_ADDR     0
#define FLD_LL_SCN_REQ_BGN_ADV_ADDR     FLD_LL_SCN_REQ_BGN_SCN_ADDR+LEN_BD_ADDR
#define FLD_LL_SCN_RSP_BGN_ADV_ADDR     0
#define FLD_LL_CONN_REQ_BGN_INI_ADDR    0
#define FLD_LL_CONN_REQ_BGN_ADV_ADDR    FLD_LL_SCN_REQ_BGN_SCN_ADDR+LEN_BD_ADDR

#define FLD_LL_CTRL_OPCODE_TRXFIFO      0
#define FLD_LL_CTRL_PARAM_BGN_TRXFIFO   1
#define FLD_LL_DATA_PARAM_BGN_TRXFIFO   0

#define LL_PARA_MIN_SCN_WINDOW          ((_TICK_BASE_MULTIPLIER_<<2)+LL_TMR_TICKS_RSV_RF_INIT)  //HCI__027
#define LL_PARA_MAX_SCN_WINDOW          65535                       //HCI__027
#define LL_PARA_MIN_INIT_WINDOW         ((_TICK_BASE_MULTIPLIER_<<2)+LL_TMR_TICKS_RSV_RF_INIT)  //LL__003
#define LL_PARA_MAX_INIT_WINDOW         65535                       //LL__003

#if _TICK_BASE_ ==  _TICK_BASE_125P00_

#define DUR_LL_TMR_TICK_BASE            1
#define DUR_LL_RSV_PRECAL               1
#define DUR_LL_RSV_SCN_BASE             (11+DUR_LL_RSV_PRECAL)
#define DUR_LL_RSV_INIT_BASE            (8+DUR_LL_RSV_PRECAL)
#define DUR_LL_RSV_CONN_NXTCH_CAL       1
//#define DUR_LL_RSV_CONN_BASE            (7+DUR_LL_RSV_CONN_NXTCH_CAL)
//#define DUR_LL_RSV_CONN_MD              (8+DUR_LL_RSV_CONN_NXTCH_CAL)
//#define DUR_LL_RSV_CONN_TXACK             (5+DUR_LL_RSV_CONN_NXTCH_CAL)
//#define DUR_LL_RSV_CONN_MD_SMS          (12+DUR_LL_RSV_CONN_NXTCH_CAL)
//#define DUR_LL_RSV_CONN_MD_MSMS         (15+DUR_LL_RSV_CONN_NXTCH_CAL)
#define DUR_LL_RSV_CONN_BASE            (36+DUR_LL_RSV_CONN_NXTCH_CAL)
#define DUR_LL_RSV_CONN_MD              (37+DUR_LL_RSV_CONN_NXTCH_CAL)
#define DUR_LL_RSV_CONN_TXACK           (20+DUR_LL_RSV_CONN_NXTCH_CAL)
#define DUR_LL_RSV_CONN_MD_SMS          (55+DUR_LL_RSV_CONN_NXTCH_CAL)
#define DUR_LL_RSV_CONN_MD_MSMS         (73+DUR_LL_RSV_CONN_NXTCH_CAL)
#define DUR_LL_RSV_CONN_WINDELAY        10
#define DUR_LL_RSV_CONN_WINOFFSET       10
#define DUR_LL_RSV_INIT_ADVEND_2_WINDELAY   (5+DUR_LL_RSV_CONN_WINDELAY)

#define DUR_LL_RSV_MIN_SCAN             6
#define DUR_LL_RSV_MIN_INIT             5
#define DUR_LL_RSV_MIN_CONN_SLV         3
#ifdef LL_PATCH_MIC_FAIL_DATA_SIZE_LESS
#define DUR_LL_RSV_MIN_AES_CCM          3   //2: normal, 3:for CCM
#else
#define DUR_LL_RSV_MIN_AES_CCM          2
#endif
#define LL_INTERVAL_DIR_ADV_HIGHDUTY    (17*3)

#else   //(#if _TICK_BASE_ ==  _TICK_BASE_125P00_)

#define DUR_LL_TMR_TICK_BASE            1
#define DUR_LL_RSV_PRECAL               1
#define DUR_LL_RSV_SCN_BASE             (9+DUR_LL_RSV_PRECAL)
#define DUR_LL_RSV_INIT_BASE            (7+DUR_LL_RSV_PRECAL)
#define DUR_LL_RSV_CONN_NXTCH_CAL       1
#define DUR_LL_RSV_CONN_BASE            (6+DUR_LL_RSV_CONN_NXTCH_CAL)
#define DUR_LL_RSV_CONN_MD              (7+DUR_LL_RSV_CONN_NXTCH_CAL)
#define DUR_LL_RSV_CONN_MD_SMS          (10+DUR_LL_RSV_CONN_NXTCH_CAL)
#define DUR_LL_RSV_CONN_MD_MSMS         (12+DUR_LL_RSV_CONN_NXTCH_CAL)
#define DUR_LL_RSV_CONN_WINDELAY        8
#define DUR_LL_RSV_CONN_WINOFFSET       8
#define DUR_LL_RSV_INIT_ADVEND_2_WINDELAY   (4+DUR_LL_RSV_CONN_WINDELAY)
#define DUR_LL_RSV_CONN_MD_MST_RX_END   5

#define DUR_LL_RSV_MIN_SCAN             5
#define DUR_LL_RSV_MIN_INIT             3
#define DUR_LL_RSV_MIN_CONN_SLV         3
//#define DUR_LL_RSV_MIN_CONN_END         2
#define DUR_LL_RSV_MIN_AES_CCM          2
#define LL_INTERVAL_DIR_ADV_HIGHDUTY    (8*3)
#endif  //(#if _TICK_BASE_ ==  _TICK_BASE_125P00_)

#define DUR_LL_RSV_MIN_TBLK_LL_ADV      1
#define DUR_LL_RSV_MIN_TBLK_LL_SCN      1
#define DUR_LL_RSV_MIN_TBLK_LL_INIT     1
#define DUR_LL_RSV_MIN_TBLK_LL_CONN     1

#if     ((DUR_LL_RSV_MIN_TBLK_LL_ADV<=DUR_LL_RSV_MIN_TBLK_LL_SCN)&&(DUR_LL_RSV_MIN_TBLK_LL_INIT<=DUR_LL_RSV_MIN_TBLK_LL_SCN))
#define DUR_LL_RSV_MIN_TBLK_LL_CMMN     DUR_LL_RSV_MIN_TBLK_LL_SCN
#elif   ((DUR_LL_RSV_MIN_TBLK_LL_ADV<=DUR_LL_RSV_MIN_TBLK_LL_INIT)&&(DUR_LL_RSV_MIN_TBLK_LL_SCN<=DUR_LL_RSV_MIN_TBLK_LL_INIT))
#define DUR_LL_RSV_MIN_TBLK_LL_CMMN     DUR_LL_RSV_MIN_TBLK_LL_INIT
#else
#define DUR_LL_RSV_MIN_TBLK_LL_CMMN     DUR_LL_RSV_MIN_TBLK_LL_ADV
#endif

#define LL_TOUT_LL_CONN                 0x6400
#define LL_TOUT_LL_CTRL                 0x7D00
#define LL_INST_MOD_LMT                 32767

#define RF_MSG_RF0INT_WTR               0x01
#define RF_MSG_RF0INT_WTR_T             0x02
//LL__022
typedef struct Adv_Param
{
    Uint8 LL_AdvMap_ID;             //addr: 00
    Uint8 LL_AdvConn_ID;            //addr: 01
    Uint8 LL_Tx_PowerLevel;         //addr: 02
    Uint16 LL_Adv_Interval_MinI;    //addr: 04
    Uint16 LL_Adv_Interval_MaxI;    //addr: 06
    Uint8 LL_Adv_Type;              //addr: 08
    Uint8 LL_Own_Addr_Type;         //addr: 09
    Uint8 LL_DirectAddr_Type;       //addr: 0A
    Uint8 LL_DirectAddr[LEN_BD_ADDR];   //addr: 0B-10
    Uint8 LL_Adv_Channel_Map;           //addr: 11
    Uint8 LL_Adv_Filter_Policy;         //addr: 12
    Uint32 LL_Adv_Interval_Min;     //addr: 14
    Uint32 LL_Adv_Interval_Max;     //addr: 18-1B
} Adv_Param;
//#define LEN_LE_ADV_PARA     (1*9+2*2+LEN_BD_ADDR+2*LEN_ADV_SCAN_DATA_MAX)
#define LEN_LE_ADV_PARAM         sizeof(Adv_Param)

typedef struct Adv_Para
{
    Uint8 LL_AdvMap_ID;             //addr: 00
    Uint8 LL_AdvConn_ID;            //addr: 01
    Uint8 LL_Tx_PowerLevel;         //addr: 02
    Uint16 LL_Adv_Interval_MinI;    //addr: 04
    Uint16 LL_Adv_Interval_MaxI;    //addr: 06
    Uint8 LL_Adv_Type;              //addr: 08
    Uint8 LL_Own_Addr_Type;         //addr: 09
    Uint8 LL_DirectAddr_Type;       //addr: 0A
    Uint8 LL_DirectAddr[LEN_BD_ADDR];   //addr: 0B-10
    Uint8 LL_Adv_Channel_Map;           //addr: 11
    Uint8 LL_Adv_Filter_Policy;         //addr: 12
    Uint32 LL_Adv_Interval_Min;     //addr: 14
    Uint32 LL_Adv_Interval_Max;     //addr: 18
    Uint8 LL_Adv_Data[LEN_ADV_SCAN_DATA_MAX];   //addr: 1C-3A
    Uint8 LL_Adv_Data_Length;           //addr: 3B
    Uint8 LL_ScanRsp_Data[LEN_ADV_SCAN_DATA_MAX];   //addr: 3C-5A
    Uint8 LL_ScanRsp_Data_Length;       //addr: 5B
} Adv_Para;
#define LEN_LE_ADV_PARA         sizeof(Adv_Para)

typedef struct Adv_Data_Buf
{
    Uint8 LL_Adv_Data[LEN_ADV_SCAN_DATA_MAX];   //addr: 00-1E
    Uint8 LL_Adv_Data_Length;           //addr: 1F
    Uint8 LL_ScanRsp_Data[LEN_ADV_SCAN_DATA_MAX];   //addr: 20-3E
    Uint8 LL_ScanRsp_Data_Length;       //addr: 3F
} Adv_Data_Buf;

typedef struct LE_Set_Scan_Para
{
    Uint8 LL_AdvMap_ID;         //addr: 00
    Uint8 LL_LE_ScanType;       //addr: 01
    Uint16 LL_LE_Scan_Interval; //addr: 02
    Uint16 LL_LE_Scan_Window;   //addr: 04
    Uint8 LL_Own_Addr_Type;     //addr: 06
    Uint8 LL_ScanFilterPolicy;  //addr: 07
    Uint16 LL_LE_ScanAccl;      //Accumulation  //addr: 08-09
    Uint8 LL_Tx_PowerLevel;     //addr: 0A
} LE_Set_Scan_Para;
//#define LEN_LE_SCAN_PARA    (1*4+2*3)
#define LEN_LE_SCAN_PARA        (sizeof(LE_Set_Scan_Para))


typedef struct LE_Conn_Para
{
    Uint8 LL_Conn_ID;                   //addr: 00
    Uint8 LL_Feature;                   //addr: 01
    Uint8 LL_Feature1;                  //addr: 02
    Uint8 LL_Tx_PowerLevel;             //addr: 03
    Uint32 LL_AccessAddr;               //addr: 04
    Uint8 LL_CRC_Init[LEN_CRC_INIT];    //addr: 08-0A
    Uint8 WinSize_DataHdr;              //addr: 0B
    Uint16 WinOffset_LtcyAccu;          //addr: 0C
    Uint16 LL_ConnInterval;             //addr: 0E
    Uint16 LL_ConnLatency;              //addr: 10
    Uint16 LL_SvisionTimeout;           //addr: 12
    Uint8 LL_ChMapReM[LEN_LL_CH_MAP];   //addr: 14-18
    Uint8 LL_HopIncrement;              //addr: 19
    Uint16 LL_EventCounter;             //addr: 1A
    Uint8 LL_CurrentCH;                 //addr: 1C
    Sint8 RF_Rssi;
    Uint16 LL_ConnIntervalOrg;          //addr: 1E
    Uint16 LL_ConnIntervalOrgUpd;       //addr: 20
    Uint8 ErrCode_DisConn;              //addr: 22
    Uint8 WinSizeUpd;                   //addr: 23
    Uint16 WinOffsetUpd;                //addr: 24
    Uint16 LL_ConnIntervalUpd;          //addr: 26
    Uint16 LL_ConnLatencyUpd;           //addr: 28
    Uint16 LL_SvisionTimeoutUpd;        //addr: 2A
    Uint16 LL_EventCounterUpd;          //addr: 2C
    Uint8 LL_RF_Data_Ch_ReM[NUM_LL_DATA_CH];    //addr: 2E-52
    Uint8 LL_SMP_Gate;                  //addr: 53
    Uint8 LL_SMP_IV_DUMP[(LEN_SMP_SKDM-LEN_SMP_IVM)];   //addr: 54-57
    Uint8 LL_SMP_IV[(LEN_SMP_IVS+LEN_SMP_IVM)];         //addr: 58-5F
    Uint8 LL_SMP_Key[LEN_AES_KEY];                      //addr: 60-6F
    Uint32 LL_SMP_packetCounterT;                       //addr: 70
    Uint8 LL_SMP_packetCounterTd;                       //addr: 74
    Uint8 LL_SMP_DataCh;                                //addr: 75
    Uint8 LL_Tx_PHYsUpd;                                //addr: 76
    Uint8 LL_Rx_PHYsUpd;                                //addr: 77
    Uint32 LL_SMP_packetCounterR;                       //addr: 78
    Uint8 LL_SMP_packetCounterRd;                       //addr: 7C
    Uint8 LL_Tx_PHYS;                                   //addr: 7D
    Uint8 LL_Rx_PHYS;                                   //addr: 7E
    Uint8 LL_Rx_length_1M;                              //addr: 7F
    Uint8 LL_Rx_length_2M;                              //addr: 80
    Uint8 LL_Tx_length_1M;                              //addr: 81
    Uint8 LL_Tx_length_2M;                              //addr: 82
    Uint8 LL_SCA;                                       //addr: 82
    Uint16 LL_SvToutAccu;                               //addr: 84
    Uint16 LL_PrToutAccu;                               //addr: 86-87
} LE_Conn_Para;         //LL__019, LL__003
#define LEN_LE_CONN_PARA        (sizeof(LE_Conn_Para))


struct Conn_Req_Para
{
    Uint8 IniAddr[LEN_BD_ADDR];     //addr: 00
    Uint8 AdvAddr[LEN_BD_ADDR];     //addr: 06
    Uint32 AccessAddr;              //addr: 0C
    Uint8 CRC_Init[LEN_CRC_INIT];   //addr: 10
    Uint8 trWinSize;                //addr: 13
    Uint16 trWinOffset;             //addr: 14
    Uint16 ConnInterval;            //addr: 16
    Uint16 ConnLatency;             //addr: 18
    Uint16 SvisionTimeout;          //addr: 1A
    Uint8 ChMap[LEN_LL_CH_MAP];     //addr: 1C
    Uint8 Hop:5;                    //addr: 21.4
    Uint8 mSCA:3;                   //addr: 21.7
};
#define LEN_LE_CONN_REQ     (1*2+2*4+4*1+LEN_BD_ADDR*2+LEN_CRC_INIT+LEN_LL_CH_MAP)


struct Conn_Req_Para_Alt
{
    Uint8 IniAddr[LEN_BD_ADDR];     //addr: 00
    Uint8 AdvAddr[LEN_BD_ADDR];     //addr: 06
    Uint32 AccessAddr;              //addr: 0C
    Uint8 CRC_Init[LEN_CRC_INIT];   //addr: 10
    Uint8 trWinSize;                //addr: 13
    Uint16 trWinOffset;             //addr: 14
    Uint16 ConnInterval;            //addr: 16
    Uint16 ConnLatency;             //addr: 18
    Uint16 SvisionTimeout;          //addr: 1A
    Uint8 ChMap[LEN_LL_CH_MAP];     //addr: 1C
    Uint8 Hop_mSCA;                 //addr: 21
};


struct LE_Init_Para
{
    Uint8 LL_Conn_ID;           //addr: 00
    Uint8 LL_AdvMap_ID;         //addr: 01
    Uint16 LL_LE_ScanAccl;      //Accumulation
    Uint16 LL_LE_Scan_Interval; //addr: 04
    Uint16 LL_LE_Scan_Window;   //addr: 06
    Uint8 LL_InitFilterPolicy;  //addr: 08
    Uint8 LL_PeerAddrType;      //addr: 09
    Uint8 LL_PeerAddr[LEN_BD_ADDR];
    Uint8 LL_Own_Addr_Type;     //addr: 10
    Uint8 LL_Tx_PowerLevel;     //addr: 11
    Uint16 LL_CE_LenMin;        //addr: 12
    Uint16 LL_CE_LenMax;
    Uint16 LL_ConnInterval;
    Uint16 LL_ConnLatency;
    Uint16 LL_SvisionTimeout;
};                              //LL__003
#define LEN_LE_INIT_PARA        (1*6+2*8+LEN_BD_ADDR)   //From LL_LE_Scan_Interval


typedef struct LE_WhiteList_Para
{
    Uint8 AddrType;             //addr: 00
    Uint8 Addr[LEN_BD_ADDR];    //addr: 01
} LE_WhiteList_Para;
#define LEN_LE_WHITELIST_PARA        sizeof(LE_WhiteList_Para)


typedef union LL_WhiteList
{
    Uint8 Data[LEN_LE_WHITELIST_PARA];
    LE_WhiteList_Para LE_WhiteList_Para;
} LL_WhiteList;


typedef union LL_Adv
{
    Uint8 Data[LEN_LE_ADV_PARA];
    Adv_Para Adv_Para;
} LL_Adv;


typedef union LL_Scan
{
    Uint8 Data[LEN_LE_SCAN_PARA];
    LE_Set_Scan_Para LE_Set_Scan_Para;
} LL_Scan;


typedef union LL_Conn
{
    Uint8 Data[LEN_LE_CONN_PARA];
    LE_Conn_Para LE_Conn_Para;
} LL_Conn;


typedef union LL_Init
{
    Uint8 Data[LEN_LE_INIT_PARA];
    struct LE_Init_Para LE_Init_Para;
} LL_Init;

#define LEN_LL_DATA_BUF         32
typedef struct LL_Para_Itrvl
{
    Uint8 DataIdxF;
    Uint8 DataIdxN;
    Uint8 HeaderSts;
    Uint8 HeaderLen;
    Uint8 Data[LEN_LL_DATA_BUF];
} LL_Para_Itrvl;

#define LEN_LL_DATA_BUFR        255
typedef struct LL_Para_ItrvlR
{
    Uint8 DataIdxF;
    Uint8 DataIdxN;
    Uint8 HeaderSts;
    Uint8 HeaderLen;
    Uint8 Data[LEN_LL_DATA_BUFR];
} LL_Para_ItrvlR;

typedef struct LL_Para_Header
{
    Uint8 HeaderSts;
    Uint8 HeaderLen;
    Uint8 Padding0;
    Uint8 Padding1;
} LL_Para_Header;


typedef struct LL_Para_Default_PHY
{
    Uint8 All_PHYs;
    Uint8 Tx_PHYs;
    Uint8 Rx_PHYs;
    Uint8 PHY_options;
} LL_Para_Default_PHY;


typedef struct BufProcess
{
    MBLK *BufPrcsF;
    MBLK *BufPrcsN;
} BufProcess;


//extern const Uint32 LL_ACCESS_ADDR_ADV;

#endif

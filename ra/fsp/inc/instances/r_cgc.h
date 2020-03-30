/***********************************************************************************************************************
 * Copyright [2020] Renesas Electronics Corporation and/or its affiliates.  All Rights Reserved.
 *
 * This software is supplied by Renesas Electronics America Inc. and may only be used with products of Renesas
 * Electronics Corp. and its affiliates ("Renesas").  No other uses are authorized.  This software is protected under
 * all applicable laws, including copyright laws. Renesas reserves the right to change or discontinue this software.
 * THE SOFTWARE IS DELIVERED TO YOU "AS IS," AND RENESAS MAKES NO REPRESENTATIONS OR WARRANTIES, AND TO THE FULLEST
 * EXTENT PERMISSIBLE UNDER APPLICABLE LAW,DISCLAIMS ALL WARRANTIES, WHETHER EXPLICITLY OR IMPLICITLY, INCLUDING
 * WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE, AND NONINFRINGEMENT, WITH RESPECT TO THE SOFTWARE.
 * TO THE MAXIMUM EXTENT PERMITTED BY LAW, IN NO EVENT WILL RENESAS BE LIABLE TO YOU IN CONNECTION WITH THE SOFTWARE
 * (OR ANY PERSON OR ENTITY CLAIMING RIGHTS DERIVED FROM YOU) FOR ANY LOSS, DAMAGES, OR CLAIMS WHATSOEVER, INCLUDING,
 * WITHOUT LIMITATION, ANY DIRECT, CONSEQUENTIAL, SPECIAL, INDIRECT, PUNITIVE, OR INCIDENTAL DAMAGES; ANY LOST PROFITS,
 * OTHER ECONOMIC DAMAGE, PROPERTY DAMAGE, OR PERSONAL INJURY; AND EVEN IF RENESAS HAS BEEN ADVISED OF THE POSSIBILITY
 * OF SUCH LOSS, DAMAGES, CLAIMS OR COSTS.
 **********************************************************************************************************************/

#ifndef R_CGC_H
#define R_CGC_H

/*******************************************************************************************************************//**
 * @addtogroup CGC
 * @{
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Includes
 **********************************************************************************************************************/
#include "bsp_api.h"
#include "r_cgc_cfg.h"
#include "r_cgc_api.h"

/* Common macro for FSP header files. There is also a corresponding FSP_FOOTER macro at the end of this file. */
FSP_HEADER

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/
#define CGC_CODE_VERSION_MAJOR    (1U)
#define CGC_CODE_VERSION_MINOR    (0U)

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

/** CGC private control block. DO NOT MODIFY. Initialization occurs when R_CGC_Open() is called. */
typedef struct st_cgc_instance_ctrl
{
    uint32_t     open;
    void const * p_context;
    void (* p_callback)(cgc_callback_args_t * p_args);
} cgc_instance_ctrl_t;

/**********************************************************************************************************************
 * Exported global variables
 **********************************************************************************************************************/

/** @cond INC_HEADER_DEFS_SEC */
/** Filled in Interface API structure for this Instance. */
extern const cgc_api_t g_cgc_on_cgc;

/** @endcond */

/***********************************************************************************************************************
 * Public APIs
 **********************************************************************************************************************/
fsp_err_t R_CGC_Open(cgc_ctrl_t * const p_ctrl, cgc_cfg_t const * const p_cfg);
fsp_err_t R_CGC_ClocksCfg(cgc_ctrl_t * const p_ctrl, cgc_clocks_cfg_t const * const p_clock_cfg);
fsp_err_t R_CGC_ClockStart(cgc_ctrl_t * const p_ctrl, cgc_clock_t clock_source, cgc_pll_cfg_t const * const p_pll_cfg);
fsp_err_t R_CGC_ClockStop(cgc_ctrl_t * const p_ctrl, cgc_clock_t clock_source);
fsp_err_t R_CGC_ClockCheck(cgc_ctrl_t * const p_ctrl, cgc_clock_t clock_source);
fsp_err_t R_CGC_SystemClockSet(cgc_ctrl_t * const              p_ctrl,
                               cgc_clock_t                     clock_source,
                               cgc_divider_cfg_t const * const p_divider_cfg);
fsp_err_t R_CGC_SystemClockGet(cgc_ctrl_t * const        p_ctrl,
                               cgc_clock_t * const       p_clock_source,
                               cgc_divider_cfg_t * const p_divider_cfg);
fsp_err_t R_CGC_OscStopDetectEnable(cgc_ctrl_t * const p_ctrl);
fsp_err_t R_CGC_OscStopDetectDisable(cgc_ctrl_t * const p_ctrl);
fsp_err_t R_CGC_OscStopStatusClear(cgc_ctrl_t * const p_ctrl);
fsp_err_t R_CGC_Close(cgc_ctrl_t * const p_ctrl);
fsp_err_t R_CGC_VersionGet(fsp_version_t * version);

/*******************************************************************************************************************//**
 * @} (end defgroup CGC)
 **********************************************************************************************************************/

/* Common macro for FSP header files. There is also a corresponding FSP_HEADER macro at the top of this file. */
FSP_FOOTER

/* R_CGC_H */
#endif                                 // R_CGC_H

/*
 * sound/soc/amlogic/auge/pdm.h
 *
 * Copyright (C) 2017 Amlogic, Inc. All rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
 * more details.
 *
 */

#ifndef __AML_PDM_H__
#define __AML_PDM_H__

#include <linux/clk.h>
#include <linux/pinctrl/consumer.h>


#define DRV_NAME "snd_pdm"

#define DEFAULT_FS_RATIO		256

#define PDM_CHANNELS_MIN		1
#define PDM_CHANNELS_MAX		(8 + 8) /* 8ch pdm in, 8 ch tdmin_lb */

#define PDM_RATES			(SNDRV_PCM_RATE_48000 |\
						SNDRV_PCM_RATE_32000 |\
						SNDRV_PCM_RATE_16000 |\
						SNDRV_PCM_RATE_8000)

#define PDM_FORMATS			(SNDRV_PCM_FMTBIT_S16_LE |\
						SNDRV_PCM_FMTBIT_S24_LE |\
						SNDRV_PCM_FMTBIT_S32_LE)

#if 1
struct aml_pdm {
	struct device *dev;
	struct aml_audio_controller *actrl;
	struct pinctrl *pdm_pins;
	struct clk *clk_gate;
	struct clk *clk_pll;
	struct clk *src_dclk;
	struct clk *clk_pdm_sysclk;
	struct clk *clk_pdm_dclk;
	struct toddr *tddr;
	/*
	 * filter mode:0~4,
	 * from mode 0 to 4, the performance is from high to low,
	 * the group delay (latency) is from high to low.
	 */
	int filter_mode;
};
#endif

#endif /*__AML_PDM_H__*/

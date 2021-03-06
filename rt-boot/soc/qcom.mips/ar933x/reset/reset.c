/*
 * The early init code for MIPS
 * Copyright ZhaoXiaowei 2018
 * Github:github.com/zhaohengbo
 */

#include <kernel/rtthread.h>
#include <common/global.h>
#include <soc/ar933x/ar933x_map.h>
#include <soc/ar933x/ar933x_reset.h>

/*
 * Performs full chip reset
 */
void ar933x_full_reset(void)
{
	volatile rt_uint32_t i = 1;

	do {
		qca_soc_reg_write(QCA_RST_RESET_REG,
						  QCA_RST_RESET_FULL_CHIP_RST_MASK
						  | QCA_RST_RESET_DDR_RST_MASK);
	} while (i);
}

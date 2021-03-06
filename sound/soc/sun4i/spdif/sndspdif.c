/*
********************************************************************************************************
*                          SUN4I----HDMI AUDIO
*                   (c) Copyright 2002-2004, All winners Co,Ld.
*                          All Right Reserved
*
* FileName: sndspdif.c   author:chenpailin  date:2011-07-19
* Description:
* Others:
* History:
*   <author>      <time>      <version>   <desc>
*   chenpailin   2011-07-19     1.0      modify this module
********************************************************************************************************
*/

#include <linux/module.h>
#include <linux/delay.h>
#include <linux/slab.h>
#include <sound/pcm.h>
#include <sound/pcm_params.h>
#include <sound/soc.h>
#include <sound/soc-dapm.h>
#include <sound/initval.h>
#include <mach/gpio_v2.h>
#include <mach/script_v2.h>
#include <linux/io.h>

static int spdif_used = 0;
#define SNDSPDIF_RATES  (SNDRV_PCM_RATE_8000_192000|SNDRV_PCM_RATE_KNOT)
#define SNDSPDIF_FORMATS (SNDRV_PCM_FMTBIT_S16_LE)

static int sndspdif_mute(struct snd_soc_dai *dai, int mute)
{
	return 0;
}

static int sndspdif_startup(struct snd_pcm_substream *substream,
	struct snd_soc_dai *dai)
{
	return 0;
}

static void sndspdif_shutdown(struct snd_pcm_substream *substream,
	struct snd_soc_dai *dai)
{
}

static int sndspdif_hw_params(struct snd_pcm_substream *substream,
	struct snd_pcm_hw_params *params,
	struct snd_soc_dai *dai)
{
	return 0;
}

static int sndspdif_set_dai_sysclk(struct snd_soc_dai *codec_dai,
				  int clk_id, unsigned int freq, int dir)
{
	return 0;
}

static int sndspdif_set_dai_clkdiv(struct snd_soc_dai *codec_dai, int div_id, int div)
{
	return 0;
}

static int sndspdif_set_dai_fmt(struct snd_soc_dai *codec_dai,
			       unsigned int fmt)
{
	return 0;
}
static struct snd_soc_dai_ops sndspdif_dai_ops = {
		.startup = sndspdif_startup,
		.shutdown = sndspdif_shutdown,
		.hw_params = sndspdif_hw_params,
		.digital_mute = sndspdif_mute,
		.set_sysclk = sndspdif_set_dai_sysclk,
		.set_clkdiv = sndspdif_set_dai_clkdiv,
		.set_fmt = sndspdif_set_dai_fmt,
};

static struct snd_soc_dai_driver sndspdif_dai = {
	.name = "sun4i-spdif-codec",
	/* playback capabilities */
	.playback = {
		.stream_name = "Playback",
		.channels_min = 1,
		.channels_max = 2,
		.rates = SNDSPDIF_RATES,
		.formats = SNDSPDIF_FORMATS,
	},
	/* pcm operations */
	.ops = &sndspdif_dai_ops,
};

static struct snd_soc_codec_driver sndspdif_codec;

static int sndspdif_soc_probe(struct platform_device *pdev)
{
	return snd_soc_register_codec(&pdev->dev,
				      &sndspdif_codec,
				      &sndspdif_dai, 1);
}

/* power down chip */
static int sndspdif_soc_remove(struct platform_device *pdev)
{
	snd_soc_unregister_codec(&pdev->dev);
	return 0;
}

static struct platform_driver sndspdif_platform_driver = {
	.driver = {
		.name = "sun4i-spdif-soc",
		.owner = THIS_MODULE,
	},
	.probe =        sndspdif_soc_probe,
	.remove =       sndspdif_soc_remove,
};

static int __init sndspdif_init(void)
{
	int ret;

	ret = script_parser_fetch("spdif_para","spdif_used", &spdif_used, sizeof(int));
	if (ret)
		printk("[SPDIF]sndspdif_init fetch spdif using configuration failed\n");

	if (spdif_used)
		return platform_driver_register(&sndspdif_platform_driver);

	printk("[SPDIF]sndspdif cannot find any using configuration for controllers, return directly!\n");
	return 0;
}
module_init(sndspdif_init);

static void __exit sndspdif_exit(void)
{
	if(spdif_used)
	{
		spdif_used = 0;
		platform_driver_unregister(&sndspdif_platform_driver);
	}
}
module_exit(sndspdif_exit);

MODULE_DESCRIPTION("SNDSPDIF ALSA soc codec driver");
MODULE_AUTHOR("Zoltan Devai, Christian Pellegrin <chripell@evolware.org>");
MODULE_LICENSE("GPL");

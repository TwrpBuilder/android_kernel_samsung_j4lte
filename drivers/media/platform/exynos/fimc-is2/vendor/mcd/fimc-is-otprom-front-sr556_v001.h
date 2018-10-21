#ifndef FIMC_IS_OTPROM_FRONT_SR556_V001_H
#define FIMC_IS_OTPROM_FRONT_SR556_V001_H

/* Header Offset Addr Section */
//#define OTP_HEADER_DIRECT_ADDR_FRONT

#define HEADER_START_ADDR_FRONT                      0x0
#define OTP_HEADER_CAL_MAP_VER_START_ADDR_FRONT      0xAB
#define OTP_HEADER_VERSION_START_ADDR_FRONT          0x60
#define OTP_HEADER_OEM_START_ADDR_FRONT              0x0
#define OTP_HEADER_OEM_END_ADDR_FRONT                0x4
#define OTP_HEADER_AWB_START_ADDR_FRONT              0x8
#define OTP_HEADER_AWB_END_ADDR_FRONT                0xC
#define OTP_HEADER_AP_SHADING_START_ADDR_FRONT       0x10
#define OTP_HEADER_AP_SHADING_END_ADDR_FRONT	     0x14
#define OTP_HEADER_PROJECT_NAME_START_ADDR_FRONT     0xB3
#define OTP_HEADER_MODULE_ID_ADDR_FRONT              0x137

/* OEM referenced section */
#define OTP_OEM_VER_START_ADDR_FRONT  	             0x282
/* AWB referenced section */
#define OTP_AWB_VER_START_ADDR_FRONT           	     0x350
/* AP Shading referenced section */
#define OTP_HEADER_SHADING_START_ADDR_FRONT          0x8C0

/* Checksum referenced section */
#define OTP_CHECKSUM_HEADER_ADDR_FRONT               0x1EC
#define OTP_CHECKSUM_OEM_ADDR_FRONT                  0x2EC
#define OTP_CHECKSUM_AWB_ADDR_FRONT                  0x3EC
#define OTP_CHECKSUM_AP_SHADING_ADDR_FRONT           0x8DC


/* AWB referenced section */
/*#define OTP_AWB_VER_START_ADDR_FRONT                 0x200*/

/* etc section */
#define FIMC_IS_MAX_CAL_SIZE_FRONT                   (8 * 1024)
#define HEADER_CRC32_LEN_FRONT                       (492)
#define OTP_USED_CAL_SIZE                            (2272)

/* Requirement Features 
 * 3 bank / need init / hynix feature*/
#define OTP_BANK
#define OTP_NEED_INIT_DIRECT  //sr556 need to sensor init before read OTP
#define CAMERA_OTPROM_SUPPORT_FRONT_HYNIX

#ifdef OTP_BANK
#define OTP_BANK_ADDR                                0x401
#define OTP_START_ADDR_BANK2                         0xD00
#define OTP_START_ADDR_BANK3                         0x15F0
#endif //OTP_BANK end
#define OTP_START_ADDR                               0x410
#define OTP_READ_ADDR                                0x108
#define OTP_READ_MODE_ADDR                           0x102
#define OTP_READ_START_ADDR_HIGH                     0x10A
#define OTP_READ_START_ADDR_LOW                      0x10B

#define OTP_MODE_CHANGE

#ifdef OTP_MODE_CHANGE
static const u32 sensor_mode_change_to_OTP_reg[] = {
	0x0A02, 0x01, 0x1,
	0x0114, 0x00, 0x1,
	0xFFFF, 0x0A, 0x1,
	0x0F02, 0x00, 0x1,
	0x011A, 0x01, 0x1,
	0x011B, 0x09, 0x1,
	0x0D04, 0x01, 0x1,
	0x0D02, 0x07, 0x1,
	0x003E, 0x10, 0x1,
	0x0114, 0x01, 0x1,
};

static const u32 sensor_mode_change_to_OTP_reg_size =
	sizeof(sensor_mode_change_to_OTP_reg) / sizeof(sensor_mode_change_to_OTP_reg[0]);

static const u32 sensor_mode_change_from_OTP_reg[] = 
{	0x0114, 0x00, 0x1,
	0x0A00, 0x00, 0x1,
	0x004A, 0x00, 0x1,
	0xFFFF, 0x0A, 0x1,
	0x0D04, 0x00, 0x1,
	0x003E, 0x00, 0x1,
	0x004A, 0x01, 0x1,
	0x0114, 0x01, 0x1,
};

static const u32 sensor_mode_change_from_OTP_reg_size =
	sizeof(sensor_mode_change_from_OTP_reg) / sizeof(sensor_mode_change_from_OTP_reg[0]);
#endif
static const u32 sensor_Global[] = {
		0x0e00,	0x0102, 0x02,
		0x0e02,	0x0102, 0x02,
		0x0e0c,	0x0100, 0x02,
		0x2000,	0x4031, 0x02,
		0x2002,	0x8400, 0x02,
		0x2004,	0x12b0, 0x02,
		0x2006,	0xe104, 0x02,
		0x2008,	0x12b0, 0x02,
		0x200a,	0xe12c, 0x02,
		0x200c,	0x12b0, 0x02,
		0x200e,	0xe142, 0x02,
		0x2010,	0x12b0, 0x02,
		0x2012,	0xe254, 0x02,
		0x2014,	0x12b0, 0x02,
		0x2016,	0xe150, 0x02,
		0x2018,	0x12b0, 0x02,
		0x201a,	0xed9e, 0x02,
		0x201c,	0x12b0, 0x02,
		0x201e,	0xe16c, 0x02,
		0x2020,	0x12b0, 0x02,
		0x2022,	0xe67e, 0x02,
		0x2024,	0x12b0, 0x02,
		0x2026,	0xe182, 0x02,
		0x2028,	0x12b0, 0x02,
		0x202a,	0xe198, 0x02,
		0x202c,	0x12b0, 0x02,
		0x202e,	0xe1ba, 0x02,
		0x2030,	0x12b0, 0x02,
		0x2032,	0xf422, 0x02,
		0x2034,	0x12b0, 0x02,
		0x2036,	0xe1c4, 0x02,
		0x2038,	0x12b0, 0x02,
		0x203a,	0xf3c2, 0x02,
		0x203c,	0x9392, 0x02,
		0x203e,	0x7114, 0x02,
		0x2040,	0x2003, 0x02,
		0x2042,	0x12b0, 0x02,
		0x2044,	0xe1fa, 0x02,
		0x2046,	0x3ffa, 0x02,
		0x2048,	0x0b00, 0x02,
		0x204a,	0x7302, 0x02,
		0x204c,	0x0036, 0x02,
		0x204e,	0x4392, 0x02,
		0x2050,	0x7902, 0x02,
		0x2052,	0x4292, 0x02,
		0x2054,	0x7100, 0x02,
		0x2056,	0x82be, 0x02,
		0x2058,	0x9382, 0x02,
		0x205a,	0x7114, 0x02,
		0x205c,	0x2403, 0x02,
		0x205e,	0x40b2, 0x02,
		0x2060,	0xd081, 0x02,
		0x2062,	0x0b88, 0x02,
		0x2064,	0x12b0, 0x02,
		0x2066,	0xe6d8, 0x02,
		0x2068,	0x12b0, 0x02,
		0x206a,	0xea1c, 0x02,
		0x206c,	0x12b0, 0x02,
		0x206e,	0xe1e4, 0x02,
		0x2070,	0x12b0, 0x02,
		0x2072,	0xe370, 0x02,
		0x2074,	0x930f, 0x02,
		0x2076,	0x27e2, 0x02,
		0x2078,	0x12b0, 0x02,
		0x207a,	0xf3da, 0x02,
		0x207c,	0x3fd5, 0x02,
		0x207e,	0x4030, 0x02,
		0x2080,	0xf750, 0x02,
		0x27fe,	0xe000, 0x02,
		0x3000,	0x70f8, 0x02,
		0x3002,	0x187f, 0x02,
		0x3004,	0x7070, 0x02,
		0x3006,	0x0114, 0x02,
		0x3008,	0x70b0, 0x02,
		0x300a,	0x1473, 0x02,
		0x300c,	0x0013, 0x02,
		0x300e,	0x140f, 0x02,
		0x3010,	0x0040, 0x02,
		0x3012,	0x100f, 0x02,
		0x3014,	0x70f8, 0x02,
		0x3016,	0x187f, 0x02,
		0x3018,	0x7070, 0x02,
		0x301a,	0x0114, 0x02,
		0x301c,	0x70b0, 0x02,
		0x301e,	0x1473, 0x02,
		0x3020,	0x0013, 0x02,
		0x3022,	0x140f, 0x02,
		0x3024,	0x0040, 0x02,
		0x3026,	0x000f, 0x02,
		0x0b00,	0x0000, 0x02,
		0x0b02,	0x0045, 0x02,
		0x0b04,	0xb405, 0x02,
		0x0b06,	0xc403, 0x02,
		0x0b08,	0x0081, 0x02,
		0x0b0a,	0x8252, 0x02,
		0x0b0c,	0xf814, 0x02,
		0x0b0e,	0xc618, 0x02,
		0x0b10,	0xa828, 0x02,
		0x0b12,	0x002c, 0x02,
		0x0b14,	0x4068, 0x02,
		0x0b16,	0x0000, 0x02,
		0x0f30,	0x6a25, 0x02,
		0x0f32,	0x7067, 0x02,
		0x0954,	0x0009, 0x02,
		0x0956,	0x0000, 0x02,
		0x0958,	0xAA80, 0x02,
		0x095a,	0x5140, 0x02,
		0x0c00,	0x1110, 0x02,
		0x0c02,	0x0011, 0x02,
		0x0c04,	0x0000, 0x02,
		0x0c06,	0x0200, 0x02,
		0x0c10,	0x0040, 0x02,
		0x0c12,	0x0040, 0x02,
		0x0c14,	0x0040, 0x02,
		0x0c16,	0x0040, 0x02,
		0x0a10,	0x4000, 0x02,
		0x3068,	0xffff, 0x02,
		0x306a,	0xffff, 0x02,
		0x006c,	0x0300, 0x02,
		0x005e,	0x0200, 0x02,
		0x000e,	0x0100, 0x02,
		0x0e0a,	0x0001, 0x02,
		0x004a,	0x0100, 0x02,
		0x004c,	0x0000, 0x02,
		0x004e,	0x0100, 0x02,
		0x000c,	0x0022, 0x02,
		0x0008,	0x0b00, 0x02,
		0x005a,	0x0202, 0x02,
		0x0012,	0x000e, 0x02,
		0x0018,	0x0a31, 0x02,
		0x0022,	0x0008, 0x02,
		0x0028,	0x0017, 0x02,
		0x0024,	0x0028, 0x02,
		0x002a,	0x002d, 0x02,
		0x0026,	0x0030, 0x02,
		0x002c,	0x07c7, 0x02,
		0x002e,	0x1111, 0x02,
		0x0030,	0x1111, 0x02,
		0x0032,	0x1111, 0x02,
		0x0006,	0x0823, 0x02,
		0x0116,	0x07b6, 0x02,
		0x0a22,	0x0000, 0x02,
		0x0a12,	0x0a20, 0x02,
		0x0a14,	0x0798, 0x02,
		0x003e,	0x0000, 0x02,
		0x0074,	0x080e, 0x02,
		0x0070,	0x0407, 0x02,
		0x0002,	0x0000, 0x02,
		0x0a02,	0x0000, 0x02,
		0x0a24,	0x0100, 0x02,
		0x0046,	0x0000, 0x02,
		0x0076,	0x0000, 0x02,
		0x0060,	0x0000, 0x02,
		0x0062,	0x0530, 0x02,
		0x0064,	0x0500, 0x02,
		0x0066,	0x0530, 0x02,
		0x0068,	0x0500, 0x02,
		0x0122,	0x0300, 0x02,
		0x015a,	0xff08, 0x02,
		0x0126,	0x00f9, 0x02,
		0x0804,	0x0200, 0x02,
		0x005c,	0x0100, 0x02,
		0x0a1a,	0x0800, 0x02,

	};
static const u32 sensor_Global_size =
	sizeof(sensor_Global) / sizeof(sensor_Global[0]);
#endif /* FIMC_IS_OTPROM_FRONT_SR556_V001_H */
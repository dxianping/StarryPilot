/*
 * File      : logger.h
 *
 *
 * Change Logs:
 * Date           Author       	Notes
 * 2018-03-29     zoujiachi   	the first version
 */
 
#ifndef __LOGGER_H__
#define __LOGGER_H__

#include <rtthread.h>
#include <rtdevice.h>

#define LOG_MAX_NAME_LENGTH		20
#define LOG_MAX_ELEMENT_NUM		100
	
#define LOG_ELEMENT_INFO_FLOAT(_name) \
			{ \
				.name = #_name, \
				.type = LOG_FLOAT \
			}
#define LOG_ELEMENT_INFO_DOUBLE(_name) \
			{ \
				.name = #_name, \
				.type = LOG_DOUBLE \
			}

#define LOG_ELEMENT_FLOAT(_name)						float _name##_elem
#define LOG_SET_ELEMENT(_logger_info, _name, _val)		_logger_info.log_field._name##_elem = _val
#define LOG_GET_ELEMENT(_logger_info, _name)			(_logger_info.log_field._name##_elem)

enum
{
	LOGGER_IDLE = 0,
	LOGGER_BUSY
};

typedef struct
{
	LOG_ELEMENT_FLOAT(ROLL);
	LOG_ELEMENT_FLOAT(PITCH);
	LOG_ELEMENT_FLOAT(YAW);
	LOG_ELEMENT_FLOAT(GYR_X);
	LOG_ELEMENT_FLOAT(GYR_Y);
	LOG_ELEMENT_FLOAT(GYR_Z);
	LOG_ELEMENT_FLOAT(GYR_FILTER_X);
	LOG_ELEMENT_FLOAT(GYR_FILTER_Y);
	LOG_ELEMENT_FLOAT(GYR_FILTER_Z);
	LOG_ELEMENT_FLOAT(ACC_X);
	LOG_ELEMENT_FLOAT(ACC_Y);
	LOG_ELEMENT_FLOAT(ACC_Z);
	LOG_ELEMENT_FLOAT(ACC_FILTER_X);
	LOG_ELEMENT_FLOAT(ACC_FILTER_Y);
	LOG_ELEMENT_FLOAT(ACC_FILTER_Z);
	LOG_ELEMENT_FLOAT(MAG_X);
	LOG_ELEMENT_FLOAT(MAG_Y);
	LOG_ELEMENT_FLOAT(MAG_Z);
	LOG_ELEMENT_FLOAT(MAG_FILTER_X);
	LOG_ELEMENT_FLOAT(MAG_FILTER_Y);
	LOG_ELEMENT_FLOAT(MAG_FILTER_Z);
	LOG_ELEMENT_FLOAT(MOTOR_1);
	LOG_ELEMENT_FLOAT(MOTOR_2);
	LOG_ELEMENT_FLOAT(MOTOR_3);
	LOG_ELEMENT_FLOAT(MOTOR_4);
	LOG_ELEMENT_FLOAT(ADRC_PITCH_SP_RATE);
	LOG_ELEMENT_FLOAT(ADRC_PITCH_V);
	LOG_ELEMENT_FLOAT(ADRC_PITCH_V1);
	LOG_ELEMENT_FLOAT(ADRC_PITCH_V2);
	LOG_ELEMENT_FLOAT(ADRC_PITCH_Z1);
	LOG_ELEMENT_FLOAT(ADRC_PITCH_Z2);
}LOG_FieldDef;

typedef struct
{
	uint8_t status;
	uint32_t log_period;
	uint32_t last_record_time;
	LOG_FieldDef log_field;
}LOGGER_InfoDef;

enum
{
	LOG_INT8 = 0,
	LOG_UINT8,
	LOG_INT16,
	LOG_UINT16,
	LOG_INT32,
	LOG_UINT32,
	LOG_FLOAT,
	LOG_DOUBLE,
};

typedef struct
{
	char name[LOG_MAX_NAME_LENGTH];
	uint32_t type;
}LOG_ElementInfoDef;

typedef struct
{
	uint32_t start_time;
	uint32_t log_period;
	uint32_t element_num;
	uint32_t header_size;
	uint32_t field_size;
	LOG_ElementInfoDef *element_info;
}LOG_HeaderDef;

void logger_entry(void *parameter);

#endif

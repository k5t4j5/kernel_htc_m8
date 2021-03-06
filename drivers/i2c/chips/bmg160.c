
/******************************************************************************
* Copyright (C) 2007 Bosch Sensortec GmbH
*
* API for BMG160
*
* Usage:        Driver for Gyro Sensor
*
* Author:       gokul.rajendran@in.bosch.com
******************************************************************************/
/*  Disclaimer
*
* Common:
* Bosch Sensortec products are developed for the consumer goods industry. They
* may only be used within the parameters of the respective valid product data
* sheet.  Bosch Sensortec products are provided with the express understanding
* that there is no warranty of fitness for a particular purpose.They are not
* fit for use in life-sustaining, safety or security sensitive systems or any
* system or device that may lead to bodily harm or property damage if the
* system or device malfunctions. In addition, Bosch Sensortec products are not
* fit for use in products which interact with motor vehicle systems.The resale
* and or use of products are at the purchasers own risk and his own
* responsibility. The examination of fitness for the intended use is the sole
* responsibility of the Purchaser.
*
* The purchaser shall indemnify Bosch Sensortec from all third party claims,
* including any claims for incidental, or consequential damages, arising from
* any product use not covered by the parameters of the respective valid product
* data sheet or not approved by Bosch Sensortec and reimburse Bosch
* Sensortec for all costs in connection with such claims.
*
* The purchaser must monitor the market for the purchased products,
* particularly with regard to product safety and inform Bosch Sensortec without
* delay of all security relevant incidents.
*
* Engineering Samples are marked with an asterisk (*) or (e). Samples may vary
* from the valid technical specifications of the product series. They are
* therefore not intended or fit for resale to third parties or for use in end
* products. Their sole purpose is internal client testing. The testing of an
* engineering sample may in no way replace the testing of a product series.
* Bosch Sensortec assumes no liability for the use of engineering samples. By
* accepting the engineering samples, the Purchaser agrees to indemnify Bosch
* Sensortec from all claims arising from the use of engineering samples.
*
* Special:
* This software module (hereinafter called "Software") and any information on
* application-sheets (hereinafter called "Information") is provided free of
* charge for the sole purpose to support your application work. The Software
* and Information is subject to the following terms and conditions:
*
* The Software is specifically designed for the exclusive use for Bosch
* Sensortec products by personnel who have special experience and training.
* Do not use this Software if you do not have the proper experience or
* training.
*
* This Software package is provided `` as is `` and without any expressed or
* implied warranties, including without limitation, the implied warranties of
* merchantability and fitness for a particular purpose.
*
* Bosch Sensortec and their representatives and agents deny any liability for
* the functional impairment of this Software in terms of fitness, performance
* and safety. Bosch Sensortec and their representatives and agents shall not be
* liable for any direct or indirect damages or injury, except as otherwise
* stipulated in mandatory applicable law.
*
* The Information provided is believed to be accurate and reliable. Bosch
* Sensortec assumes no responsibility for the consequences of use of such
* Information nor for any infringement of patents or other rights of third
* parties which may result from its use. No license is granted by implication
* or otherwise under any patent or patent rights of Bosch. Specifications
* mentioned in the Information are subject to change without notice.
*
* It is not allowed to deliver the source code of the Software to any third
* party without permission of Bosch Sensortec.
*/
#include <linux/bmg160.h>
struct bmg160_t *p_bmg160;


BMG160_RETURN_FUNCTION_TYPE bmg160_init(struct bmg160_t *bmg160)
{
	BMG160_RETURN_FUNCTION_TYPE comres = 0;
	unsigned char a_data_u8r;
	p_bmg160 = bmg160;

	p_bmg160->dev_addr = BMG160_I2C_ADDR;

	
	comres = p_bmg160->BMG160_BUS_READ_FUNC(p_bmg160->dev_addr,\
	 BMG160_CHIP_ID_ADDR, &a_data_u8r, 1);
	p_bmg160->chip_id = a_data_u8r;
	return comres;
}
BMG160_RETURN_FUNCTION_TYPE bmg160_get_dataX(BMG160_S16 *data_x)
{
	BMG160_RETURN_FUNCTION_TYPE comres;
	unsigned char a_data_u8r[2];
	if (p_bmg160 == BMG160_NULL) {
		comres = E_BMG160_NULL_PTR;
	} else {
		comres = p_bmg160->BMG160_BUS_READ_FUNC(p_bmg160->dev_addr,\
		 BMG160_RATE_X_LSB_VALUEX__REG, a_data_u8r, 2);
		a_data_u8r[0] = BMG160_GET_BITSLICE(a_data_u8r[0],\
		BMG160_RATE_X_LSB_VALUEX);
		*data_x = (BMG160_S16)\
		((((BMG160_S16)((signed char)a_data_u8r[1])) << \
		BMG160_SHIFT_8_POSITION) | (a_data_u8r[0]));
	}
	return comres;
}
BMG160_RETURN_FUNCTION_TYPE bmg160_get_dataY(BMG160_S16 *data_y)
{
	BMG160_RETURN_FUNCTION_TYPE comres;
	unsigned char a_data_u8r[2];
	if (p_bmg160 == BMG160_NULL) {
		comres = E_BMG160_NULL_PTR;
	} else {
		comres = p_bmg160->BMG160_BUS_READ_FUNC(p_bmg160->dev_addr,\
		 BMG160_RATE_Y_LSB_VALUEY__REG, a_data_u8r, 2);
		a_data_u8r[0] = BMG160_GET_BITSLICE(a_data_u8r[0],\
		BMG160_RATE_Y_LSB_VALUEY);
		*data_y = (BMG160_S16)\
		((((BMG160_S16)((signed char)a_data_u8r[1]))\
		<< BMG160_SHIFT_8_POSITION) | (a_data_u8r[0]));
	}
	return comres;
}
BMG160_RETURN_FUNCTION_TYPE bmg160_get_dataZ(BMG160_S16 *data_z)
{
	BMG160_RETURN_FUNCTION_TYPE comres;
	unsigned char a_data_u8r[2];
	if (p_bmg160 == BMG160_NULL) {
		comres = E_BMG160_NULL_PTR;
	} else {
		comres = p_bmg160->BMG160_BUS_READ_FUNC(p_bmg160->dev_addr,\
		 BMG160_RATE_Z_LSB_VALUEZ__REG, a_data_u8r, 2);
		a_data_u8r[0] = BMG160_GET_BITSLICE(a_data_u8r[0],\
		BMG160_RATE_Z_LSB_VALUEZ);
		*data_z = (BMG160_S16)\
		((((BMG160_S16)((signed char)a_data_u8r[1]))\
		<< BMG160_SHIFT_8_POSITION) | (a_data_u8r[0]));
	}
	return comres;
}
BMG160_RETURN_FUNCTION_TYPE bmg160_get_dataXYZ(struct bmg160_data_t *data)
{
	BMG160_RETURN_FUNCTION_TYPE comres;
	unsigned char a_data_u8r[6];
	if (p_bmg160 == BMG160_NULL) {
		comres = E_BMG160_NULL_PTR;
	} else {
		comres = p_bmg160->BMG160_BUS_READ_FUNC(p_bmg160->dev_addr,\
		 BMG160_RATE_X_LSB_VALUEX__REG, a_data_u8r, 6);
		
		a_data_u8r[0] = \
		BMG160_GET_BITSLICE(a_data_u8r[0], BMG160_RATE_X_LSB_VALUEX);
		data->datax = (BMG160_S16)\
		((((BMG160_S16)((signed char)a_data_u8r[1]))\
		<< BMG160_SHIFT_8_POSITION) | (a_data_u8r[0]));
		
		a_data_u8r[2] = BMG160_GET_BITSLICE(a_data_u8r[2],\
		BMG160_RATE_Y_LSB_VALUEY);
		data->datay = (BMG160_S16)\
		((((BMG160_S16)((signed char)a_data_u8r[3]))\
		<< BMG160_SHIFT_8_POSITION) | (a_data_u8r[2]));
		
		a_data_u8r[4] = BMG160_GET_BITSLICE(a_data_u8r[4],\
		BMG160_RATE_Z_LSB_VALUEZ);
		data->dataz = (BMG160_S16)\
		((((BMG160_S16)((signed char)a_data_u8r[5]))\
		<< BMG160_SHIFT_8_POSITION) | (a_data_u8r[4]));
	}
	return comres;
}
BMG160_RETURN_FUNCTION_TYPE bmg160_get_dataXYZI(struct bmg160_data_t *data)
{
	BMG160_RETURN_FUNCTION_TYPE comres;
	unsigned char a_data_u8r[12];
	if (p_bmg160 == BMG160_NULL) {
		comres = E_BMG160_NULL_PTR;
	} else {
		comres = p_bmg160->BMG160_BUS_READ_FUNC(p_bmg160->dev_addr,\
		 BMG160_RATE_X_LSB_VALUEX__REG, a_data_u8r, 12);
		
		a_data_u8r[0] = BMG160_GET_BITSLICE(a_data_u8r[0],\
		BMG160_RATE_X_LSB_VALUEX);
		data->datax = (BMG160_S16)\
		((((BMG160_S16)((signed char)a_data_u8r[1]))\
		<< BMG160_SHIFT_8_POSITION) | (a_data_u8r[0]));
		
		a_data_u8r[2] = BMG160_GET_BITSLICE(a_data_u8r[2],\
		BMG160_RATE_Y_LSB_VALUEY);
		data->datay = (BMG160_S16)\
		((((BMG160_S16)((signed char)a_data_u8r[3]))\
		<< BMG160_SHIFT_8_POSITION) | (a_data_u8r[2]));
		
		a_data_u8r[4] = BMG160_GET_BITSLICE(a_data_u8r[4],\
		BMG160_RATE_Z_LSB_VALUEZ);
		data->dataz = (BMG160_S16)\
		((((BMG160_S16)((signed char)a_data_u8r[5]))\
		<< BMG160_SHIFT_8_POSITION) | (a_data_u8r[4]));
		data->intstatus[0] = a_data_u8r[7];
		data->intstatus[1] = a_data_u8r[8];
		data->intstatus[2] = a_data_u8r[9];
		data->intstatus[3] = a_data_u8r[10];
		data->intstatus[4] = a_data_u8r[11];
	}
	return comres;
}
BMG160_RETURN_FUNCTION_TYPE bmg160_get_Temperature(unsigned char *temperature)
{
	BMG160_RETURN_FUNCTION_TYPE comres;
	unsigned char v_data_u8r;
	if (p_bmg160 == BMG160_NULL) {
		comres = E_BMG160_NULL_PTR;
	} else {
		comres = p_bmg160->BMG160_BUS_READ_FUNC(p_bmg160->dev_addr,\
		 BMG160_TEMP_ADDR, &v_data_u8r, 1);
		*temperature = v_data_u8r;
	}
	return comres;
}
BMG160_RETURN_FUNCTION_TYPE bmg160_read_register(unsigned char addr,\
unsigned char *data, unsigned char len)
{
	BMG160_RETURN_FUNCTION_TYPE comres;
	if (p_bmg160 == BMG160_NULL) {
		comres = E_BMG160_NULL_PTR;
	} else {
		comres = p_bmg160->BMG160_BUS_READ_FUNC\
		(p_bmg160->dev_addr, addr, data, len);
	}
	return comres;
}
BMG160_RETURN_FUNCTION_TYPE bmg160_burst_read(unsigned char addr,\
unsigned char reg, unsigned char *data, BMG160_S32 len)
{
	BMG160_RETURN_FUNCTION_TYPE comres;
	if (p_bmg160 == BMG160_NULL) {
		comres = E_BMG160_NULL_PTR;
	} else {
		comres = p_bmg160->BMG160_BURST_READ_FUNC(p_bmg160->dev_addr,\
		addr, data, len);
	}
	return comres;
}
/**\brief This API given data to the given register
 *
 *
 *
 *
 *  \param unsigned char addr, unsigned char data,unsigned char len
 *                   addr -> Address of the register
 *                   data -> Data to be written to the register
 *					len -> No of byte to be read.
 *
 *  \return Results of bus communication function
 *
 *
 *****************************************************************************/
BMG160_RETURN_FUNCTION_TYPE bmg160_write_register(unsigned char addr,\
unsigned char *data, unsigned char len)
{
	BMG160_RETURN_FUNCTION_TYPE comres;
	if (p_bmg160 == BMG160_NULL) {
		comres = E_BMG160_NULL_PTR;
	} else {
		comres = p_bmg160->BMG160_BUS_WRITE_FUNC\
		(p_bmg160->dev_addr, addr, data, len);
	}
	return comres;
}

BMG160_RETURN_FUNCTION_TYPE bmg160_get_interrupt_status_reg_0(\
unsigned char *status0_data)
{
	BMG160_RETURN_FUNCTION_TYPE comres;
	unsigned char v_data_u8r;
	if (p_bmg160 == BMG160_NULL) {
		comres = E_BMG160_NULL_PTR;
	} else {
		comres = p_bmg160->BMG160_BUS_READ_FUNC\
		(p_bmg160->dev_addr,\
		BMG160_INT_STATUSZERO__REG, &v_data_u8r, 1);
		*status0_data = \
		BMG160_GET_BITSLICE(v_data_u8r, BMG160_INT_STATUSZERO);
	}
	return comres;
}

BMG160_RETURN_FUNCTION_TYPE bmg160_get_interrupt_status_reg_1(\
unsigned char *status1_data)
{
	BMG160_RETURN_FUNCTION_TYPE comres;
	unsigned char v_data_u8r;
	if (p_bmg160 == BMG160_NULL) {
		comres = E_BMG160_NULL_PTR;
	} else {
		comres = p_bmg160->BMG160_BUS_READ_FUNC\
		(p_bmg160->dev_addr, BMG160_INT_STATUSONE__REG,\
		&v_data_u8r, 1);
		*status1_data = \
		BMG160_GET_BITSLICE(v_data_u8r, BMG160_INT_STATUSONE);
	}
	return comres;
}

BMG160_RETURN_FUNCTION_TYPE bmg160_get_interrupt_status_reg_2(\
unsigned char *status2_data)
{
	BMG160_RETURN_FUNCTION_TYPE comres;
	unsigned char v_data_u8r;
	if (p_bmg160 == BMG160_NULL) {
		comres = E_BMG160_NULL_PTR;
	} else {
		comres = p_bmg160->BMG160_BUS_READ_FUNC\
		(p_bmg160->dev_addr, \
		BMG160_INT_STATUSTWO__REG, &v_data_u8r, 1);
		*status2_data =\
		BMG160_GET_BITSLICE(v_data_u8r, BMG160_INT_STATUSTWO);
	}
	return comres;
}

BMG160_RETURN_FUNCTION_TYPE bmg160_get_interrupt_status_reg_3(\
unsigned char *status3_data)
{
	BMG160_RETURN_FUNCTION_TYPE comres;
	unsigned char v_data_u8r;
	if (p_bmg160 == BMG160_NULL) {
		comres = E_BMG160_NULL_PTR;
	} else {
		comres = p_bmg160->BMG160_BUS_READ_FUNC\
		(p_bmg160->dev_addr,\
		BMG160_INT_STATUSTHREE__REG, &v_data_u8r, 1);
		*status3_data =\
		BMG160_GET_BITSLICE(v_data_u8r, BMG160_INT_STATUSTHREE);
	}
	return comres;
}
BMG160_RETURN_FUNCTION_TYPE bmg160_get_range_reg(unsigned char *range)
{
	BMG160_RETURN_FUNCTION_TYPE comres;
	unsigned char v_data_u8r;
	if (p_bmg160 == BMG160_NULL) {
		comres = E_BMG160_NULL_PTR;
	} else {
		comres = p_bmg160->BMG160_BUS_READ_FUNC\
		(p_bmg160->dev_addr,\
		BMG160_RANGE_ADDR_RANGE__REG, &v_data_u8r, 1);
		*range =\
		BMG160_GET_BITSLICE(v_data_u8r, BMG160_RANGE_ADDR_RANGE);
	}
	return comres;
}
BMG160_RETURN_FUNCTION_TYPE bmg160_set_range_reg(unsigned char range)
{
	BMG160_RETURN_FUNCTION_TYPE comres;
	unsigned char v_data_u8r;
	if (p_bmg160 == BMG160_NULL) {
		comres = E_BMG160_NULL_PTR;
	} else {
		if (range < C_BMG160_Five_U8X) {
			comres = p_bmg160->BMG160_BUS_READ_FUNC\
			(p_bmg160->dev_addr,\
			BMG160_RANGE_ADDR_RANGE__REG, &v_data_u8r, 1);
			v_data_u8r = BMG160_SET_BITSLICE(v_data_u8r,\
			BMG160_RANGE_ADDR_RANGE,\
			range);
			comres = p_bmg160->BMG160_BUS_WRITE_FUNC\
			(p_bmg160->dev_addr,\
			BMG160_RANGE_ADDR_RANGE__REG, &v_data_u8r, 1);
		} else {
			comres = E_BMG160_OUT_OF_RANGE;
		}
	}
	return comres;
}
BMG160_RETURN_FUNCTION_TYPE bmg160_get_high_res(unsigned char *high_res)
{
	BMG160_RETURN_FUNCTION_TYPE comres;
	unsigned char v_data_u8r;
	if (p_bmg160 == BMG160_NULL) {
		comres = E_BMG160_NULL_PTR;
	} else {
		comres = p_bmg160->BMG160_BUS_READ_FUNC \
		(p_bmg160->dev_addr,\
		BMG160_BW_ADDR_HIGH_RES__REG, &v_data_u8r, 1);
		*high_res = \
		BMG160_GET_BITSLICE(v_data_u8r, BMG160_BW_ADDR_HIGH_RES);
	}
	return comres;
}
BMG160_RETURN_FUNCTION_TYPE bmg160_get_bw(unsigned char *bandwidth)
{
	BMG160_RETURN_FUNCTION_TYPE comres;
	unsigned char v_data_u8r;
	if (p_bmg160 == BMG160_NULL) {
		comres = E_BMG160_NULL_PTR;
	} else {
		comres = p_bmg160->BMG160_BUS_READ_FUNC\
		(p_bmg160->dev_addr, BMG160_BW_ADDR__REG, &v_data_u8r, 1);
		*bandwidth = BMG160_GET_BITSLICE(v_data_u8r,\
			BMG160_BW_ADDR);
	}
	return comres;
}
BMG160_RETURN_FUNCTION_TYPE bmg160_set_bw(unsigned char bandwidth)
{
	BMG160_RETURN_FUNCTION_TYPE comres;
	unsigned char v_data_u8r;
	unsigned char v_mode_u8r;
	unsigned char v_autosleepduration;
	if (p_bmg160 == BMG160_NULL) {
		comres = E_BMG160_NULL_PTR;
	} else {
		if (bandwidth < C_BMG160_Eight_U8X) {
			bmg160_get_mode(&v_mode_u8r);
			if (v_mode_u8r == BMG160_MODE_ADVANCEDPOWERSAVING) {
				bmg160_get_autosleepdur(&v_autosleepduration);
				bmg160_set_autosleepdur(v_autosleepduration, \
				bandwidth);
			}
			comres = p_bmg160->BMG160_BUS_READ_FUNC\
			(p_bmg160->dev_addr,\
			BMG160_BW_ADDR__REG, &v_data_u8r, 1);
			v_data_u8r = BMG160_SET_BITSLICE(v_data_u8r,\
				BMG160_BW_ADDR, bandwidth);
			comres = p_bmg160->BMG160_BUS_WRITE_FUNC\
				(p_bmg160->dev_addr,\
			BMG160_BW_ADDR__REG, &v_data_u8r, 1);
		} else {
			comres = E_BMG160_OUT_OF_RANGE;
		}
	}
	return comres;
}
BMG160_RETURN_FUNCTION_TYPE bmg160_get_pmu_ext_tri_sel(\
unsigned char *pwu_ext_tri_sel)
{
	BMG160_RETURN_FUNCTION_TYPE comres;
	unsigned char v_data_u8r;
	if (p_bmg160 == BMG160_NULL) {
		comres = E_BMG160_NULL_PTR;
	} else {
		comres = p_bmg160->BMG160_BUS_READ_FUNC(p_bmg160->dev_addr,\
		 BMG160_MODE_LPM2_ADDR_EXT_TRI_SEL__REG, &v_data_u8r, 1);
		*pwu_ext_tri_sel = BMG160_GET_BITSLICE(v_data_u8r,\
		BMG160_MODE_LPM2_ADDR_EXT_TRI_SEL);
	}
	return comres;
}
/**\brief This API writes the External Trigger selection
 * bits (4 and 5) of 0x12h registers
 *
 *
 *
 *
 *  \param unsigned char pwu_ext_tri_sel
 *               Value to be written passed as a parameter
 *
 *
 *
 *  \return Communication Results
 *
 *
 *****************************************************************************/
BMG160_RETURN_FUNCTION_TYPE bmg160_set_pmu_ext_tri_sel(\
unsigned char pwu_ext_tri_sel)
{
	BMG160_RETURN_FUNCTION_TYPE comres;
	unsigned char v_data_u8r;
	if (p_bmg160 == BMG160_NULL) {
		comres = E_BMG160_NULL_PTR;
	} else {
		comres = p_bmg160->BMG160_BUS_READ_FUNC(p_bmg160->dev_addr,\
		BMG160_MODE_LPM2_ADDR_EXT_TRI_SEL__REG, &v_data_u8r, 1);
		v_data_u8r = BMG160_SET_BITSLICE(v_data_u8r,\
		BMG160_MODE_LPM2_ADDR_EXT_TRI_SEL, pwu_ext_tri_sel);
		comres = p_bmg160->BMG160_BUS_WRITE_FUNC(p_bmg160->dev_addr,\
		BMG160_MODE_LPM2_ADDR_EXT_TRI_SEL__REG, &v_data_u8r, 1);
	}
	return comres;
}
BMG160_RETURN_FUNCTION_TYPE bmg160_get_high_bw(unsigned char *high_bw)
{
	BMG160_RETURN_FUNCTION_TYPE comres;
	unsigned char v_data_u8r;
	if (p_bmg160 == BMG160_NULL) {
		comres = E_BMG160_NULL_PTR;
	} else {
		comres = p_bmg160->BMG160_BUS_READ_FUNC(p_bmg160->dev_addr,\
		 BMG160_RATED_HBW_ADDR_DATA_HIGHBW__REG, &v_data_u8r, 1);
		*high_bw = BMG160_GET_BITSLICE(v_data_u8r,\
		BMG160_RATED_HBW_ADDR_DATA_HIGHBW);
	}
	return comres;
}
/**\brief This API is used to set data high bandwidth
 *
 *
 *
 *
 *  \param unsigned char high_bw:
 *          Value to be written passed as a parameter
 *
 *
 *
 *  \return communication results
 *
 *
 *****************************************************************************/
BMG160_RETURN_FUNCTION_TYPE bmg160_set_high_bw(unsigned char high_bw)
{
	BMG160_RETURN_FUNCTION_TYPE comres;
	unsigned char v_data_u8r;
	if (p_bmg160 == BMG160_NULL) {
		comres = E_BMG160_NULL_PTR;
	} else {
		if (high_bw < C_BMG160_Two_U8X) {
			comres = p_bmg160->BMG160_BUS_READ_FUNC\
				(p_bmg160->dev_addr,\
			BMG160_RATED_HBW_ADDR_DATA_HIGHBW__REG,\
			&v_data_u8r, 1);
			v_data_u8r = BMG160_SET_BITSLICE(v_data_u8r,\
			BMG160_RATED_HBW_ADDR_DATA_HIGHBW, high_bw);
			comres = p_bmg160->BMG160_BUS_WRITE_FUNC\
				(p_bmg160->dev_addr,\
			BMG160_RATED_HBW_ADDR_DATA_HIGHBW__REG,\
			&v_data_u8r, 1);
		} else {
			comres = E_BMG160_OUT_OF_RANGE;
		}
	}
	return comres;
}
BMG160_RETURN_FUNCTION_TYPE bmg160_get_shadow_dis(unsigned char *shadow_dis)
{
	BMG160_RETURN_FUNCTION_TYPE comres;
	unsigned char v_data_u8r;
	if (p_bmg160 == BMG160_NULL) {
		comres = E_BMG160_NULL_PTR;
	} else {
		comres = p_bmg160->BMG160_BUS_READ_FUNC(p_bmg160->dev_addr,\
		BMG160_RATED_HBW_ADDR_SHADOW_DIS__REG, &v_data_u8r, 1);
		*shadow_dis = BMG160_GET_BITSLICE(v_data_u8r,\
		BMG160_RATED_HBW_ADDR_SHADOW_DIS);
	}
	return comres;
}
/**\brief This API is used to set shadow dis
 *
 *
 *
 *
 *  \param unsigned char shadow_dis
 *         Value to be written passed as a parameter
 *
 *
 *
 *
 *  \return communication results
 *
 *
 *****************************************************************************/
BMG160_RETURN_FUNCTION_TYPE bmg160_set_shadow_dis(unsigned char shadow_dis)
{
	BMG160_RETURN_FUNCTION_TYPE comres;
	unsigned char v_data_u8r;
	if (p_bmg160 == BMG160_NULL) {
		comres = E_BMG160_NULL_PTR;
	} else {
		if (shadow_dis < C_BMG160_Two_U8X) {
			comres = p_bmg160->BMG160_BUS_READ_FUNC\
			(p_bmg160->dev_addr,\
			BMG160_RATED_HBW_ADDR_SHADOW_DIS__REG, &v_data_u8r, 1);
			v_data_u8r = BMG160_SET_BITSLICE(v_data_u8r,\
			BMG160_RATED_HBW_ADDR_SHADOW_DIS, shadow_dis);
			comres = p_bmg160->BMG160_BUS_WRITE_FUNC\
				(p_bmg160->dev_addr,\
			BMG160_RATED_HBW_ADDR_SHADOW_DIS__REG, &v_data_u8r, 1);
		} else {
			comres = E_BMG160_OUT_OF_RANGE;
		}
	}
	return comres;
}
/**\brief
 *               This function is used for the soft reset
 *     The soft reset register will be written with 0xB6.
 *
 *
 *
 *  \param  None
 *
 *
 *
 *  \return Communication results.
 *
 *
 *****************************************************************************/
BMG160_RETURN_FUNCTION_TYPE bmg160_set_soft_reset()
{
	BMG160_RETURN_FUNCTION_TYPE comres;
	unsigned char v_SoftReset_u8r;
	v_SoftReset_u8r = 0xB6;
	if (p_bmg160 == BMG160_NULL) {
		comres = E_BMG160_NULL_PTR;
	} else {
		comres = p_bmg160->BMG160_BUS_WRITE_FUNC(p_bmg160->dev_addr,\
		BMG160_BGW_SOFTRESET_ADDR, &v_SoftReset_u8r, 1);
	}
	return comres;
}
BMG160_RETURN_FUNCTION_TYPE bmg160_get_data_enable(unsigned char *data_en)
{
	BMG160_RETURN_FUNCTION_TYPE comres;
	unsigned char v_data_u8r;
	if (p_bmg160 == BMG160_NULL) {
		comres = E_BMG160_NULL_PTR;
	} else {
		comres = p_bmg160->BMG160_BUS_READ_FUNC(p_bmg160->dev_addr,\
		 BMG160_INT_ENABLE0_DATAEN__REG, &v_data_u8r, 1);
		*data_en = BMG160_GET_BITSLICE(v_data_u8r,\
			BMG160_INT_ENABLE0_DATAEN);
	}
	return comres;
}
/**\brief This API is used to set data enable data
 *
 *
 *
 *
 *  \param unsigned char data_en:
 *          Value to be written passed as a parameter
 *           0 --> Disable
 *           1 --> Enable
 *
 *
 *
 *  \return communication results
 *
 *
 *****************************************************************************/
BMG160_RETURN_FUNCTION_TYPE bmg160_set_data_en(unsigned char data_en)
{
	BMG160_RETURN_FUNCTION_TYPE comres;
	unsigned char v_data_u8r;
	if (p_bmg160 == BMG160_NULL) {
		comres = E_BMG160_NULL_PTR;
	} else {
		comres = p_bmg160->BMG160_BUS_READ_FUNC\
			(p_bmg160->dev_addr,\
		BMG160_INT_ENABLE0_DATAEN__REG, &v_data_u8r, 1);
		v_data_u8r = BMG160_SET_BITSLICE(v_data_u8r,\
		BMG160_INT_ENABLE0_DATAEN, data_en);
		comres = p_bmg160->BMG160_BUS_WRITE_FUNC\
			(p_bmg160->dev_addr,\
		BMG160_INT_ENABLE0_DATAEN__REG, &v_data_u8r, 1);
	}
	return comres;
}
BMG160_RETURN_FUNCTION_TYPE bmg160_get_fifo_enable(unsigned char *fifo_en)
{
	BMG160_RETURN_FUNCTION_TYPE comres;
	unsigned char v_data_u8r;
	if (p_bmg160 == BMG160_NULL) {
		comres = E_BMG160_NULL_PTR;
	} else {
		comres = p_bmg160->BMG160_BUS_READ_FUNC(p_bmg160->dev_addr,\
		 BMG160_INT_ENABLE0_FIFOEN__REG, &v_data_u8r, 1);
		*fifo_en = BMG160_GET_BITSLICE(v_data_u8r,\
			BMG160_INT_ENABLE0_FIFOEN);
	}
	return comres;
}
/**\brief This API is used to set fifo enable bit
 *
 *
 *
 *
 *  \param unsigned char fifo_en:
 *          Value to be written passed as a parameter
 *           0 --> Disable
 *           1 --> Enable
 *
 *
 *
 *  \return communication results
 *
 *
 *****************************************************************************/
BMG160_RETURN_FUNCTION_TYPE bmg160_set_fifo_enable(unsigned char fifo_en)
{
	BMG160_RETURN_FUNCTION_TYPE comres;
	unsigned char v_data_u8r;
	if (p_bmg160 == BMG160_NULL) {
		comres = E_BMG160_NULL_PTR;
	} else {
		if (fifo_en < C_BMG160_Two_U8X) {
			comres = p_bmg160->BMG160_BUS_READ_FUNC\
				(p_bmg160->dev_addr,\
			BMG160_INT_ENABLE0_FIFOEN__REG, &v_data_u8r, 1);
			v_data_u8r = BMG160_SET_BITSLICE(v_data_u8r,\
			BMG160_INT_ENABLE0_FIFOEN, fifo_en);
			comres = p_bmg160->BMG160_BUS_WRITE_FUNC\
				(p_bmg160->dev_addr,\
			BMG160_INT_ENABLE0_FIFOEN__REG, &v_data_u8r, 1);
		} else {
			comres = E_BMG160_OUT_OF_RANGE;
		}
	}
	return comres;
}
BMG160_RETURN_FUNCTION_TYPE bmg160_get_auto_offset_en(\
unsigned char *offset_en)
{
	BMG160_RETURN_FUNCTION_TYPE comres;
	unsigned char v_data_u8r;
	if (p_bmg160 == BMG160_NULL) {
		comres = E_BMG160_NULL_PTR;
	} else {
		comres = p_bmg160->BMG160_BUS_READ_FUNC(p_bmg160->dev_addr,\
		 BMG160_INT_ENABLE0_AUTO_OFFSETEN__REG, &v_data_u8r, 1);
		*offset_en = BMG160_GET_BITSLICE(v_data_u8r,\
		BMG160_INT_ENABLE0_AUTO_OFFSETEN);
	}
	return comres;
}
BMG160_RETURN_FUNCTION_TYPE bmg160_set_auto_offset_en(unsigned char offset_en)
{
	BMG160_RETURN_FUNCTION_TYPE comres;
	unsigned char v_data_u8r;
	if (p_bmg160 == BMG160_NULL) {
		comres = E_BMG160_NULL_PTR;
	} else {
		comres = p_bmg160->BMG160_BUS_READ_FUNC(p_bmg160->dev_addr,\
		BMG160_INT_ENABLE0_AUTO_OFFSETEN__REG, &v_data_u8r, 1);
		v_data_u8r = BMG160_SET_BITSLICE(v_data_u8r,\
		BMG160_INT_ENABLE0_AUTO_OFFSETEN, offset_en);
		comres = p_bmg160->BMG160_BUS_WRITE_FUNC(p_bmg160->dev_addr,\
		BMG160_INT_ENABLE0_AUTO_OFFSETEN__REG, &v_data_u8r, 1);
	}
	return comres;
}
BMG160_RETURN_FUNCTION_TYPE bmg160_get_int_od(unsigned char param,\
unsigned char *int_od)
{
	BMG160_RETURN_FUNCTION_TYPE comres;
	unsigned char v_data_u8r;
	if (p_bmg160 == BMG160_NULL) {
		comres = E_BMG160_NULL_PTR;
	} else {
		switch (param) {
		case BMG160_INT1:
			comres = p_bmg160->BMG160_BUS_READ_FUNC\
				(p_bmg160->dev_addr,\
			 BMG160_INT_ENABLE1_IT1_OD__REG, &v_data_u8r, 1);
			*int_od = BMG160_GET_BITSLICE(v_data_u8r,\
			BMG160_INT_ENABLE1_IT1_OD);
			break;
		case BMG160_INT2:
			comres = p_bmg160->BMG160_BUS_READ_FUNC\
				(p_bmg160->dev_addr,\
			 BMG160_INT_ENABLE1_IT2_OD__REG, &v_data_u8r, 1);
			*int_od = BMG160_GET_BITSLICE(v_data_u8r,\
			BMG160_INT_ENABLE1_IT2_OD);
			break;
		default:
			comres = E_BMG160_OUT_OF_RANGE;
			break;
		}
	}
	return comres;
}
BMG160_RETURN_FUNCTION_TYPE bmg160_set_int_od(unsigned char param,\
unsigned char int_od)
{
	BMG160_RETURN_FUNCTION_TYPE comres;
	unsigned char v_data_u8r;
	if (p_bmg160 == BMG160_NULL) {
		comres = E_BMG160_NULL_PTR;
	} else {
		switch (param) {
		case BMG160_INT1:
			comres = p_bmg160->BMG160_BUS_READ_FUNC\
				(p_bmg160->dev_addr,\
			BMG160_INT_ENABLE1_IT1_OD__REG, &v_data_u8r, 1);
			v_data_u8r = BMG160_SET_BITSLICE(v_data_u8r,\
			BMG160_INT_ENABLE1_IT1_OD, int_od);
			comres = p_bmg160->BMG160_BUS_WRITE_FUNC\
				(p_bmg160->dev_addr,\
			BMG160_INT_ENABLE1_IT1_OD__REG, &v_data_u8r, 1);
			break;
		case BMG160_INT2:
			comres = p_bmg160->BMG160_BUS_READ_FUNC\
				(p_bmg160->dev_addr,\
			BMG160_INT_ENABLE1_IT2_OD__REG, &v_data_u8r, 1);
			v_data_u8r = BMG160_SET_BITSLICE(v_data_u8r,\
			BMG160_INT_ENABLE1_IT2_OD, int_od);
			comres = p_bmg160->BMG160_BUS_WRITE_FUNC\
				(p_bmg160->dev_addr,\
			BMG160_INT_ENABLE1_IT2_OD__REG, &v_data_u8r, 1);
			break;
		default:
			comres = E_BMG160_OUT_OF_RANGE;
			break;
		}
	}
	return comres;
}
BMG160_RETURN_FUNCTION_TYPE bmg160_get_int_lvl(unsigned char param,\
unsigned char *int_lvl)
{
	BMG160_RETURN_FUNCTION_TYPE comres;
	unsigned char v_data_u8r;
	if (p_bmg160 == BMG160_NULL) {
		comres = E_BMG160_NULL_PTR;
	} else {
		switch (param) {
		case BMG160_INT1:
			comres = p_bmg160->BMG160_BUS_READ_FUNC\
				(p_bmg160->dev_addr,\
			 BMG160_INT_ENABLE1_IT1_LVL__REG, &v_data_u8r, 1);
			*int_lvl = BMG160_GET_BITSLICE(v_data_u8r,\
			BMG160_INT_ENABLE1_IT1_LVL);
			break;
		case BMG160_INT2:
			comres = p_bmg160->BMG160_BUS_READ_FUNC\
				(p_bmg160->dev_addr,\
			 BMG160_INT_ENABLE1_IT2_LVL__REG, &v_data_u8r, 1);
			*int_lvl = BMG160_GET_BITSLICE(v_data_u8r,\
			BMG160_INT_ENABLE1_IT2_LVL);
			break;
		default:
			comres = E_BMG160_OUT_OF_RANGE;
			break;
		}
	}
	return comres;
}
BMG160_RETURN_FUNCTION_TYPE bmg160_set_int_lvl(unsigned char param,\
unsigned char int_lvl)
{
	BMG160_RETURN_FUNCTION_TYPE comres;
	unsigned char v_data_u8r;
	if (p_bmg160 == BMG160_NULL) {
		comres = E_BMG160_NULL_PTR;
	} else {
		switch (param) {
		case BMG160_INT1:
			comres = p_bmg160->BMG160_BUS_READ_FUNC\
				(p_bmg160->dev_addr,\
			BMG160_INT_ENABLE1_IT1_LVL__REG, &v_data_u8r, 1);
			v_data_u8r = BMG160_SET_BITSLICE(v_data_u8r,\
			BMG160_INT_ENABLE1_IT1_LVL, int_lvl);
			comres = p_bmg160->BMG160_BUS_WRITE_FUNC\
				(p_bmg160->dev_addr,\
			BMG160_INT_ENABLE1_IT1_LVL__REG, &v_data_u8r, 1);
			break;
		case BMG160_INT2:
			comres = p_bmg160->BMG160_BUS_READ_FUNC\
				(p_bmg160->dev_addr,\
			BMG160_INT_ENABLE1_IT2_LVL__REG, &v_data_u8r, 1);
			v_data_u8r = BMG160_SET_BITSLICE(v_data_u8r,\
			BMG160_INT_ENABLE1_IT2_LVL, int_lvl);
			comres = p_bmg160->BMG160_BUS_WRITE_FUNC\
				(p_bmg160->dev_addr,\
			BMG160_INT_ENABLE1_IT2_LVL__REG, &v_data_u8r, 1);
			break;
		default:
			comres = E_BMG160_OUT_OF_RANGE;
			break;
		}
	}
	return comres;
}
BMG160_RETURN_FUNCTION_TYPE bmg160_get_int1_high(unsigned char *int1_high)
{
	BMG160_RETURN_FUNCTION_TYPE comres;
	unsigned char v_data_u8r;
	if (p_bmg160 == BMG160_NULL) {
		comres = E_BMG160_NULL_PTR;
	} else {
		comres = p_bmg160->BMG160_BUS_READ_FUNC(p_bmg160->dev_addr,\
		 BMG160_INT_MAP_0_INT1_HIGH__REG, &v_data_u8r, 1);
		*int1_high = BMG160_GET_BITSLICE(v_data_u8r,\
			BMG160_INT_MAP_0_INT1_HIGH);
	}
	return comres;
}
BMG160_RETURN_FUNCTION_TYPE bmg160_set_int1_high(unsigned char int1_high)
{
	BMG160_RETURN_FUNCTION_TYPE comres;
	unsigned char v_data_u8r;
	if (p_bmg160 == BMG160_NULL) {
		comres = E_BMG160_NULL_PTR;
	} else {
		comres = p_bmg160->BMG160_BUS_READ_FUNC(p_bmg160->dev_addr,\
		BMG160_INT_MAP_0_INT1_HIGH__REG, &v_data_u8r, 1);
		v_data_u8r = BMG160_SET_BITSLICE(v_data_u8r,\
		BMG160_INT_MAP_0_INT1_HIGH, int1_high);
		comres = p_bmg160->BMG160_BUS_WRITE_FUNC(p_bmg160->dev_addr,\
		BMG160_INT_MAP_0_INT1_HIGH__REG, &v_data_u8r, 1);
	}
	return comres;
}
BMG160_RETURN_FUNCTION_TYPE bmg160_get_int1_any(unsigned char *int1_any)
{
	BMG160_RETURN_FUNCTION_TYPE comres;
	unsigned char v_data_u8r;
	if (p_bmg160 == BMG160_NULL) {
		comres = E_BMG160_NULL_PTR;
	} else {
		comres = p_bmg160->BMG160_BUS_READ_FUNC(p_bmg160->dev_addr,\
		 BMG160_INT_MAP_0_INT1_ANY__REG, &v_data_u8r, 1);
		*int1_any = BMG160_GET_BITSLICE(v_data_u8r,\
			BMG160_INT_MAP_0_INT1_ANY);
	}
	return comres;
}
BMG160_RETURN_FUNCTION_TYPE bmg160_set_int1_any(unsigned char int1_any)
{
	BMG160_RETURN_FUNCTION_TYPE comres;
	unsigned char v_data_u8r;
	if (p_bmg160 == BMG160_NULL) {
		comres = E_BMG160_NULL_PTR;
	} else {
		comres = p_bmg160->BMG160_BUS_READ_FUNC(p_bmg160->dev_addr,\
		BMG160_INT_MAP_0_INT1_ANY__REG, &v_data_u8r, 1);
		v_data_u8r = BMG160_SET_BITSLICE(v_data_u8r,\
		BMG160_INT_MAP_0_INT1_ANY, int1_any);
		comres = p_bmg160->BMG160_BUS_WRITE_FUNC(p_bmg160->dev_addr,\
		BMG160_INT_MAP_0_INT1_ANY__REG, &v_data_u8r, 1);
	}
	return comres;
}
BMG160_RETURN_FUNCTION_TYPE bmg160_get_int_data(unsigned char axis,\
unsigned char *int_data)
{
	BMG160_RETURN_FUNCTION_TYPE comres;
	unsigned char v_data_u8r;
	if (p_bmg160 == BMG160_NULL) {
		comres = E_BMG160_NULL_PTR;
	} else {
		switch (axis) {
		case BMG160_INT1_DATA:
			comres = p_bmg160->BMG160_BUS_READ_FUNC\
				(p_bmg160->dev_addr,\
			 BMG160_MAP_1_INT1_DATA__REG, &v_data_u8r, 1);
			*int_data = BMG160_GET_BITSLICE(v_data_u8r,\
				BMG160_MAP_1_INT1_DATA);
			break;
		case BMG160_INT2_DATA:
			comres = p_bmg160->BMG160_BUS_READ_FUNC\
				(p_bmg160->dev_addr,\
			 BMG160_MAP_1_INT2_DATA__REG, &v_data_u8r, 1);
			*int_data = BMG160_GET_BITSLICE(v_data_u8r,\
				BMG160_MAP_1_INT2_DATA);
			break;
		default:
			comres = E_BMG160_OUT_OF_RANGE;
			break;
		}
	}
	return comres;
}
BMG160_RETURN_FUNCTION_TYPE bmg160_set_int_data(unsigned char axis,\
unsigned char int_data)
{
	BMG160_RETURN_FUNCTION_TYPE comres;
	unsigned char v_data_u8r;
	if (p_bmg160 == BMG160_NULL) {
		comres = E_BMG160_NULL_PTR;
	} else {
		if (axis == BMG160_INT1_DATA) {
			comres = E_BMG160_NULL_PTR;
		} else {
			switch (axis) {
			case BMG160_INT1_DATA:
				comres = p_bmg160->BMG160_BUS_READ_FUNC\
					(p_bmg160->dev_addr,\
				BMG160_MAP_1_INT1_DATA__REG, &v_data_u8r, 1);
				v_data_u8r = BMG160_SET_BITSLICE(v_data_u8r,\
				BMG160_MAP_1_INT1_DATA, int_data);
				comres = p_bmg160->BMG160_BUS_WRITE_FUNC\
					(p_bmg160->dev_addr,\
				BMG160_MAP_1_INT1_DATA__REG, &v_data_u8r, 1);
				break;
			case BMG160_INT2_DATA:
				comres = p_bmg160->BMG160_BUS_READ_FUNC\
					(p_bmg160->dev_addr,\
				BMG160_MAP_1_INT2_DATA__REG, &v_data_u8r, 1);
				v_data_u8r = BMG160_SET_BITSLICE(v_data_u8r,\
				BMG160_MAP_1_INT2_DATA, int_data);
				comres = p_bmg160->BMG160_BUS_WRITE_FUNC\
					(p_bmg160->dev_addr,\
				BMG160_MAP_1_INT2_DATA__REG, &v_data_u8r, 1);
				break;
			default:
				comres = E_BMG160_OUT_OF_RANGE;
				break;
			}
		}
	}
	return comres;
}
BMG160_RETURN_FUNCTION_TYPE bmg160_get_int2_offset(unsigned char axis,\
unsigned char *int2_offset)
{
	BMG160_RETURN_FUNCTION_TYPE comres;
	unsigned char v_data_u8r;
	if (p_bmg160 == BMG160_NULL) {
		comres = E_BMG160_NULL_PTR;
	} else {
		switch (axis) {
		case BMG160_FAST_OFFSET:
			comres = p_bmg160->BMG160_BUS_READ_FUNC\
				(p_bmg160->dev_addr,\
			 BMG160_MAP_1_INT2_FAST_OFFSET__REG, &v_data_u8r, 1);
			*int2_offset = BMG160_GET_BITSLICE(v_data_u8r,\
			BMG160_MAP_1_INT2_FAST_OFFSET);
			break;
		case BMG160_AUTO_OFFSET:
			comres = p_bmg160->BMG160_BUS_READ_FUNC\
				(p_bmg160->dev_addr,\
			 BMG160_MAP_1_INT2_AUTO_OFFSET__REG, &v_data_u8r, 1);
			*int2_offset = BMG160_GET_BITSLICE(v_data_u8r,\
			BMG160_MAP_1_INT2_AUTO_OFFSET);
			break;
		default:
			comres = E_BMG160_OUT_OF_RANGE;
			break;
		}
	}
	return comres;
}
BMG160_RETURN_FUNCTION_TYPE bmg160_set_int2_offset(unsigned char axis,\
unsigned char int2_offset)
{
	BMG160_RETURN_FUNCTION_TYPE comres;
	unsigned char v_data_u8r;
	if (p_bmg160 == BMG160_NULL) {
		comres = E_BMG160_NULL_PTR;
	} else {
		switch (axis) {
		case BMG160_FAST_OFFSET:
			comres = p_bmg160->BMG160_BUS_READ_FUNC\
				(p_bmg160->dev_addr,\
			BMG160_MAP_1_INT2_FAST_OFFSET__REG, &v_data_u8r, 1);
			v_data_u8r = BMG160_SET_BITSLICE(v_data_u8r,\
			BMG160_MAP_1_INT2_FAST_OFFSET, int2_offset);
			comres = p_bmg160->BMG160_BUS_WRITE_FUNC\
				(p_bmg160->dev_addr,\
			BMG160_MAP_1_INT2_FAST_OFFSET__REG, &v_data_u8r, 1);
			break;
		case BMG160_AUTO_OFFSET:
			comres = p_bmg160->BMG160_BUS_READ_FUNC\
				(p_bmg160->dev_addr,\
			BMG160_MAP_1_INT2_AUTO_OFFSET__REG, &v_data_u8r, 1);
			v_data_u8r = BMG160_SET_BITSLICE(v_data_u8r,\
			BMG160_MAP_1_INT2_AUTO_OFFSET, int2_offset);
			comres = p_bmg160->BMG160_BUS_WRITE_FUNC\
				(p_bmg160->dev_addr,\
			BMG160_MAP_1_INT2_AUTO_OFFSET__REG, &v_data_u8r, 1);
			break;
		default:
			comres = E_BMG160_OUT_OF_RANGE;
			break;
		}
	}
	return comres;
}
BMG160_RETURN_FUNCTION_TYPE bmg160_get_int1_offset(unsigned char axis,\
unsigned char *int1_offset)
{
	BMG160_RETURN_FUNCTION_TYPE comres;
	unsigned char v_data_u8r;
	if (p_bmg160 == BMG160_NULL) {
		comres = E_BMG160_NULL_PTR;
	} else {
		switch (axis) {
		case BMG160_FAST_OFFSET:
			comres = p_bmg160->BMG160_BUS_READ_FUNC\
				(p_bmg160->dev_addr,\
			 BMG160_MAP_1_INT1_FAST_OFFSET__REG, &v_data_u8r, 1);
			*int1_offset = BMG160_GET_BITSLICE(v_data_u8r,\
			BMG160_MAP_1_INT1_FAST_OFFSET);
			break;
		case BMG160_AUTO_OFFSET:
			comres = p_bmg160->BMG160_BUS_READ_FUNC\
				(p_bmg160->dev_addr,\
			 BMG160_MAP_1_INT1_AUTO_OFFSET__REG, &v_data_u8r, 1);
			*int1_offset = BMG160_GET_BITSLICE(v_data_u8r,\
			BMG160_MAP_1_INT1_AUTO_OFFSET);
			break;
		default:
			comres = E_BMG160_OUT_OF_RANGE;
			break;
		}
	}
	return comres;
}
BMG160_RETURN_FUNCTION_TYPE bmg160_set_int1_offset(unsigned char axis,\
unsigned char int1_offset)
{
	BMG160_RETURN_FUNCTION_TYPE comres;
	unsigned char v_data_u8r;
	if (p_bmg160 == BMG160_NULL) {
		comres = E_BMG160_NULL_PTR;
	} else {
		switch (axis) {
		case BMG160_FAST_OFFSET:
			comres = p_bmg160->BMG160_BUS_READ_FUNC\
				(p_bmg160->dev_addr,\
			BMG160_MAP_1_INT1_FAST_OFFSET__REG, &v_data_u8r, 1);
			v_data_u8r = BMG160_SET_BITSLICE(v_data_u8r,\
			BMG160_MAP_1_INT1_FAST_OFFSET, int1_offset);
			comres = p_bmg160->BMG160_BUS_WRITE_FUNC\
				(p_bmg160->dev_addr,\
			BMG160_MAP_1_INT1_FAST_OFFSET__REG, &v_data_u8r, 1);
			break;
		case BMG160_AUTO_OFFSET:
			comres = p_bmg160->BMG160_BUS_READ_FUNC\
				(p_bmg160->dev_addr,\
			BMG160_MAP_1_INT1_AUTO_OFFSET__REG, &v_data_u8r, 1);
			v_data_u8r = BMG160_SET_BITSLICE(v_data_u8r,\
			BMG160_MAP_1_INT1_AUTO_OFFSET, int1_offset);
			comres = p_bmg160->BMG160_BUS_WRITE_FUNC\
				(p_bmg160->dev_addr,\
			BMG160_MAP_1_INT1_AUTO_OFFSET__REG, &v_data_u8r, 1);
			break;
		default:
			comres = E_BMG160_OUT_OF_RANGE;
			break;
		}
	}
	return comres;
}
BMG160_RETURN_FUNCTION_TYPE bmg160_get_int_fifo(unsigned char *int_fifo)
{
	BMG160_RETURN_FUNCTION_TYPE comres;
	unsigned char v_data_u8r;
	if (p_bmg160 == BMG160_NULL) {
		comres = E_BMG160_NULL_PTR;
	} else {
		comres = p_bmg160->BMG160_BUS_READ_FUNC(p_bmg160->dev_addr,\
		 BMG160_INT_STATUS1_FIFO_INT__REG, &v_data_u8r, 1);
		*int_fifo = BMG160_GET_BITSLICE(v_data_u8r,\
			BMG160_INT_STATUS1_FIFO_INT);
	}
	return comres;
}
BMG160_RETURN_FUNCTION_TYPE bmg160_get_int2_fifo(unsigned char *int_fifo)
{
	BMG160_RETURN_FUNCTION_TYPE comres;
	unsigned char v_data_u8r;
	if (p_bmg160 == BMG160_NULL) {
		comres = E_BMG160_NULL_PTR;
	} else {
		comres = p_bmg160->BMG160_BUS_READ_FUNC(p_bmg160->dev_addr,\
		BMG160_MAP_1_INT2_FIFO__REG, &v_data_u8r, 1);
		*int_fifo = BMG160_GET_BITSLICE(v_data_u8r,\
			BMG160_MAP_1_INT2_FIFO);
	}
	return comres;
}
BMG160_RETURN_FUNCTION_TYPE bmg160_get_int1_fifo(unsigned char *int_fifo)
{
	BMG160_RETURN_FUNCTION_TYPE comres;
	unsigned char v_data_u8r;
	if (p_bmg160 == BMG160_NULL) {
		comres = E_BMG160_NULL_PTR;
	} else {
		comres = p_bmg160->BMG160_BUS_READ_FUNC(p_bmg160->dev_addr,\
		 BMG160_MAP_1_INT1_FIFO__REG, &v_data_u8r, 1);
		*int_fifo = BMG160_GET_BITSLICE(v_data_u8r,\
			BMG160_MAP_1_INT1_FIFO);
	}
	return comres;
}
BMG160_RETURN_FUNCTION_TYPE bmg160_set_int_fifo(unsigned char axis,\
unsigned char int_fifo)
{
	BMG160_RETURN_FUNCTION_TYPE comres;
	unsigned char v_data_u8r;
	if (p_bmg160 == BMG160_NULL) {
		comres = E_BMG160_NULL_PTR;
	} else {
		switch (axis) {
		case BMG160_INT1:
			comres = p_bmg160->BMG160_BUS_READ_FUNC\
				(p_bmg160->dev_addr,\
			 BMG160_MAP_1_INT1_FIFO__REG, &v_data_u8r, 1);
			v_data_u8r = BMG160_SET_BITSLICE(v_data_u8r,\
			BMG160_MAP_1_INT1_FIFO, int_fifo);
			comres = p_bmg160->BMG160_BUS_WRITE_FUNC\
				(p_bmg160->dev_addr,\
			BMG160_MAP_1_INT1_FIFO__REG, &v_data_u8r, 1);
			break;
		case BMG160_INT2:
			comres = p_bmg160->BMG160_BUS_READ_FUNC\
				(p_bmg160->dev_addr,\
			BMG160_MAP_1_INT2_FIFO__REG, &v_data_u8r, 1);
			v_data_u8r = BMG160_SET_BITSLICE(v_data_u8r,\
			BMG160_MAP_1_INT2_FIFO, int_fifo);
			comres = p_bmg160->BMG160_BUS_WRITE_FUNC\
				(p_bmg160->dev_addr,\
			BMG160_MAP_1_INT2_FIFO__REG, &v_data_u8r, 1);
			break;
		default:
			comres = E_BMG160_OUT_OF_RANGE;
			break;
		}
	}
	return comres;
}
BMG160_RETURN_FUNCTION_TYPE bmg160_set_int1_fifo(unsigned char fifo_int1)
{
	BMG160_RETURN_FUNCTION_TYPE comres;
	unsigned char v_data_u8r;
	if (p_bmg160 == BMG160_NULL) {
		comres = E_BMG160_NULL_PTR;
	} else {
		if (fifo_int1 < C_BMG160_Two_U8X) {
			comres = p_bmg160->BMG160_BUS_READ_FUNC\
				(p_bmg160->dev_addr,\
			BMG160_MAP_1_INT1_FIFO__REG, &v_data_u8r, 1);
			v_data_u8r = BMG160_SET_BITSLICE(v_data_u8r,\
			BMG160_MAP_1_INT1_FIFO, fifo_int1);
			comres = p_bmg160->BMG160_BUS_WRITE_FUNC\
				(p_bmg160->dev_addr,\
			BMG160_MAP_1_INT1_FIFO__REG, &v_data_u8r, 1);
		} else {
			comres = E_BMG160_OUT_OF_RANGE;
		}
	}
	return comres;
}
BMG160_RETURN_FUNCTION_TYPE bmg160_set_int2_fifo(unsigned char fifo_int2)
{
	BMG160_RETURN_FUNCTION_TYPE comres;
	unsigned char v_data_u8r;
	if (p_bmg160 == BMG160_NULL) {
		comres = E_BMG160_NULL_PTR;
	} else {
		if (fifo_int2 < C_BMG160_Two_U8X) {
			comres = p_bmg160->BMG160_BUS_READ_FUNC\
				(p_bmg160->dev_addr,\
			BMG160_MAP_1_INT2_FIFO__REG, &v_data_u8r, 1);
			v_data_u8r = BMG160_SET_BITSLICE(v_data_u8r,\
			BMG160_MAP_1_INT2_FIFO, fifo_int2);
			comres = p_bmg160->BMG160_BUS_WRITE_FUNC\
				(p_bmg160->dev_addr,\
			BMG160_MAP_1_INT2_FIFO__REG, &v_data_u8r, 1);
		} else {
			comres = E_BMG160_OUT_OF_RANGE;
		}
	}
	return comres;
}
BMG160_RETURN_FUNCTION_TYPE bmg160_get_int2_high(unsigned char *int2_high)
{
	BMG160_RETURN_FUNCTION_TYPE comres;
	unsigned char v_data_u8r;
	if (p_bmg160 == BMG160_NULL) {
		comres = E_BMG160_NULL_PTR;
	} else {
		comres = p_bmg160->BMG160_BUS_READ_FUNC(p_bmg160->dev_addr,\
		BMG160_INT_MAP_2_INT2_HIGH__REG, &v_data_u8r, 1);
		*int2_high = BMG160_GET_BITSLICE(v_data_u8r,\
			BMG160_INT_MAP_2_INT2_HIGH);
	}
	return comres;
}
BMG160_RETURN_FUNCTION_TYPE bmg160_set_int2_high(unsigned char int2_high)
{
	BMG160_RETURN_FUNCTION_TYPE comres;
	unsigned char v_data_u8r;
	if (p_bmg160 == BMG160_NULL) {
		comres = E_BMG160_NULL_PTR;
	} else {
		comres = p_bmg160->BMG160_BUS_READ_FUNC(p_bmg160->dev_addr,\
		BMG160_INT_MAP_2_INT2_HIGH__REG, &v_data_u8r, 1);
		v_data_u8r = BMG160_SET_BITSLICE(v_data_u8r,\
		BMG160_INT_MAP_2_INT2_HIGH, int2_high);
		comres = p_bmg160->BMG160_BUS_WRITE_FUNC(p_bmg160->dev_addr,\
		BMG160_INT_MAP_2_INT2_HIGH__REG, &v_data_u8r, 1);
	}
	return comres;
}
BMG160_RETURN_FUNCTION_TYPE bmg160_get_int2_any(unsigned char *int2_any)
{
	BMG160_RETURN_FUNCTION_TYPE comres;
	unsigned char v_data_u8r;
	if (p_bmg160 == BMG160_NULL) {
		comres = E_BMG160_NULL_PTR;
	} else {
		comres = p_bmg160->BMG160_BUS_READ_FUNC(p_bmg160->dev_addr,\
		BMG160_INT_MAP_2_INT2_ANY__REG, &v_data_u8r, 1);
		*int2_any = BMG160_GET_BITSLICE(v_data_u8r,\
			BMG160_INT_MAP_2_INT2_ANY);
	}
	return comres;
}
BMG160_RETURN_FUNCTION_TYPE bmg160_set_int2_any(unsigned char int2_any)
{
	BMG160_RETURN_FUNCTION_TYPE comres;
	unsigned char v_data_u8r;
	if (p_bmg160 == BMG160_NULL) {
		comres = E_BMG160_NULL_PTR;
	} else {
		comres = p_bmg160->BMG160_BUS_READ_FUNC(p_bmg160->dev_addr,\
		BMG160_INT_MAP_2_INT2_ANY__REG, &v_data_u8r, 1);
		v_data_u8r = BMG160_SET_BITSLICE(v_data_u8r,\
		BMG160_INT_MAP_2_INT2_ANY, int2_any);
		comres = p_bmg160->BMG160_BUS_WRITE_FUNC(p_bmg160->dev_addr,\
		BMG160_INT_MAP_2_INT2_ANY__REG, &v_data_u8r, 1);
	}
	return comres;
}
BMG160_RETURN_FUNCTION_TYPE bmg160_get_offset_unfilt(unsigned char param,\
unsigned char *offset_unfilt)
{
	BMG160_RETURN_FUNCTION_TYPE comres;
	unsigned char v_data_u8r;
	if (p_bmg160 == BMG160_NULL) {
		comres = E_BMG160_NULL_PTR;
	} else {
		switch (param) {
		case BMG160_SLOW_OFFSET:
			comres = p_bmg160->BMG160_BUS_READ_FUNC\
				(p_bmg160->dev_addr,\
			BMG160_INT_0_ADDR_SLOW_OFFSET_UNFILT__REG,\
			&v_data_u8r, 1);
			*offset_unfilt = BMG160_GET_BITSLICE(v_data_u8r,\
			BMG160_INT_0_ADDR_SLOW_OFFSET_UNFILT);
			break;
		case BMG160_FAST_OFFSET:
			comres = p_bmg160->BMG160_BUS_READ_FUNC\
				(p_bmg160->dev_addr,\
			BMG160_INT_1_ADDR_FAST_OFFSET_UNFILT__REG,\
			&v_data_u8r, 1);
			*offset_unfilt = BMG160_GET_BITSLICE(v_data_u8r,\
			BMG160_INT_1_ADDR_FAST_OFFSET_UNFILT);
			break;
		default:
			comres = E_BMG160_OUT_OF_RANGE;
			break;
		}
	}
	return comres;
}
BMG160_RETURN_FUNCTION_TYPE bmg160_set_offset_unfilt(unsigned char param,\
unsigned char offset_unfilt)
{
	BMG160_RETURN_FUNCTION_TYPE comres;
	unsigned char v_data_u8r;
	if (p_bmg160 == BMG160_NULL) {
		comres = E_BMG160_NULL_PTR;
	} else {
		switch (param) {
		case BMG160_SLOW_OFFSET:
			comres = p_bmg160->BMG160_BUS_READ_FUNC\
				(p_bmg160->dev_addr,\
			BMG160_INT_0_ADDR_SLOW_OFFSET_UNFILT__REG,\
			&v_data_u8r, 1);
			v_data_u8r = BMG160_SET_BITSLICE(v_data_u8r,\
			BMG160_INT_0_ADDR_SLOW_OFFSET_UNFILT, offset_unfilt);
			comres = p_bmg160->BMG160_BUS_WRITE_FUNC\
				(p_bmg160->dev_addr,\
			BMG160_INT_0_ADDR_SLOW_OFFSET_UNFILT__REG,\
			&v_data_u8r, 1);
			break;
		case BMG160_FAST_OFFSET:
			comres = p_bmg160->BMG160_BUS_READ_FUNC\
				(p_bmg160->dev_addr,\
			BMG160_INT_1_ADDR_FAST_OFFSET_UNFILT__REG,\
			&v_data_u8r, 1);
			v_data_u8r = BMG160_SET_BITSLICE(v_data_u8r,\
			BMG160_INT_1_ADDR_FAST_OFFSET_UNFILT, offset_unfilt);
			comres = p_bmg160->BMG160_BUS_WRITE_FUNC\
				(p_bmg160->dev_addr,\
			BMG160_INT_1_ADDR_FAST_OFFSET_UNFILT__REG,\
			&v_data_u8r, 1);
			break;
		default:
			comres = E_BMG160_OUT_OF_RANGE;
			break;
		}
	}
	return comres;
}
BMG160_RETURN_FUNCTION_TYPE bmg160_get_unfilt_data(unsigned char param,\
unsigned char *unfilt_data)
{
	BMG160_RETURN_FUNCTION_TYPE comres;
	unsigned char v_data_u8r;
	if (p_bmg160 == BMG160_NULL) {
		comres = E_BMG160_NULL_PTR;
	} else {
		switch (param) {
		case BMG160_HIGH_UNFILT_DATA:
			comres = p_bmg160->BMG160_BUS_READ_FUNC\
				(p_bmg160->dev_addr,\
			BMG160_INT_0_ADDR_HIGH_UNFILT_DATA__REG,\
			&v_data_u8r, 1);
			*unfilt_data = BMG160_GET_BITSLICE(v_data_u8r,\
			BMG160_INT_0_ADDR_HIGH_UNFILT_DATA);
			break;
		case BMG160_ANY_UNFILT_DATA:
			comres = p_bmg160->BMG160_BUS_READ_FUNC\
				(p_bmg160->dev_addr,\
			BMG160_INT_0_ADDR_ANY_UNFILT_DATA__REG, &v_data_u8r, 1);
			*unfilt_data = BMG160_GET_BITSLICE(v_data_u8r,\
			BMG160_INT_0_ADDR_ANY_UNFILT_DATA);
			break;
		default:
			comres = E_BMG160_OUT_OF_RANGE;
			break;
		}
	}
	return comres;
}
BMG160_RETURN_FUNCTION_TYPE bmg160_set_unfilt_data(unsigned char param,\
unsigned char unfilt_data)
{
	BMG160_RETURN_FUNCTION_TYPE comres;
	unsigned char v_data_u8r;
	if (p_bmg160 == BMG160_NULL) {
		comres = E_BMG160_NULL_PTR;
	} else {
		switch (param) {
		case BMG160_HIGH_UNFILT_DATA:
			comres = p_bmg160->BMG160_BUS_READ_FUNC\
				(p_bmg160->dev_addr,\
			BMG160_INT_0_ADDR_HIGH_UNFILT_DATA__REG,\
			&v_data_u8r, 1);
			v_data_u8r = BMG160_SET_BITSLICE(v_data_u8r,\
			BMG160_INT_0_ADDR_HIGH_UNFILT_DATA, unfilt_data);
			comres = p_bmg160->BMG160_BUS_WRITE_FUNC\
				(p_bmg160->dev_addr,\
			BMG160_INT_0_ADDR_HIGH_UNFILT_DATA__REG,\
			&v_data_u8r, 1);
			break;
		case BMG160_ANY_UNFILT_DATA:
			comres = p_bmg160->BMG160_BUS_READ_FUNC\
				(p_bmg160->dev_addr,\
			BMG160_INT_0_ADDR_ANY_UNFILT_DATA__REG, &v_data_u8r, 1);
			v_data_u8r = BMG160_SET_BITSLICE(v_data_u8r,\
			BMG160_INT_0_ADDR_ANY_UNFILT_DATA, unfilt_data);
			comres = p_bmg160->BMG160_BUS_WRITE_FUNC\
				(p_bmg160->dev_addr,\
			BMG160_INT_0_ADDR_ANY_UNFILT_DATA__REG, &v_data_u8r, 1);
			break;
		default:
			comres = E_BMG160_OUT_OF_RANGE;
			break;
		}
	}
	return comres;
}
BMG160_RETURN_FUNCTION_TYPE bmg160_get_any_th(unsigned char *any_th)
{
	BMG160_RETURN_FUNCTION_TYPE comres;
	unsigned char v_data_u8r;
	if (p_bmg160 == BMG160_NULL) {
		comres = E_BMG160_NULL_PTR;
	} else {
		comres = p_bmg160->BMG160_BUS_READ_FUNC(p_bmg160->dev_addr,\
		BMG160_INT_1_ADDR_ANY_TH__REG, &v_data_u8r, 1);
		*any_th = BMG160_GET_BITSLICE(v_data_u8r,\
			BMG160_INT_1_ADDR_ANY_TH);
	}
	return comres;
}
/**\brief This API is used to set Any Threshold
 *
 *
 *
 *
 *  \param unsigned char any_th:
 *          Value to be written passed as a parameter
 *
 *
 *
 *  \return communication results
 *
 *
 *****************************************************************************/
BMG160_RETURN_FUNCTION_TYPE bmg160_set_any_th(unsigned char any_th)
{
	BMG160_RETURN_FUNCTION_TYPE comres;
	unsigned char v_data_u8r;
	if (p_bmg160 == BMG160_NULL) {
		comres = E_BMG160_NULL_PTR;
	} else {
		comres = p_bmg160->BMG160_BUS_READ_FUNC(p_bmg160->dev_addr,\
		BMG160_INT_1_ADDR_ANY_TH__REG, &v_data_u8r, 1);
		v_data_u8r = BMG160_SET_BITSLICE(v_data_u8r,\
		BMG160_INT_1_ADDR_ANY_TH, any_th);
		comres = p_bmg160->BMG160_BUS_WRITE_FUNC(p_bmg160->dev_addr,\
		BMG160_INT_1_ADDR_ANY_TH__REG, &v_data_u8r, 1);
	}
	return comres;
}
BMG160_RETURN_FUNCTION_TYPE bmg160_get_awake_dur(unsigned char *awake_dur)
{
	BMG160_RETURN_FUNCTION_TYPE comres;
	unsigned char v_data_u8r;
	if (p_bmg160 == BMG160_NULL) {
		comres = E_BMG160_NULL_PTR;
	} else {
		comres = p_bmg160->BMG160_BUS_READ_FUNC(p_bmg160->dev_addr,\
		BMG160_INT_2_ADDR_AWAKE_DUR__REG, &v_data_u8r, 1);
		*awake_dur = BMG160_GET_BITSLICE(v_data_u8r,\
			BMG160_INT_2_ADDR_AWAKE_DUR);
	}
	return comres;
}
/**\brief This API is used to set Awake Duration
 *
 *
 *
 *
 *  \param unsigned char awake_dur:
 *          Value to be written passed as a parameter
 *
 *
 *
 *  \return communication results
 *
 *
 *****************************************************************************
 * Scheduling:
 *
 *
 *
 * Usage guide:
 *
 *
 * Remarks:
 *
 *****************************************************************************/
BMG160_RETURN_FUNCTION_TYPE bmg160_set_awake_dur(unsigned char awake_dur)
{
	BMG160_RETURN_FUNCTION_TYPE comres;
	unsigned char v_data_u8r;
	if (p_bmg160 == BMG160_NULL) {
		comres = E_BMG160_NULL_PTR;
	} else {
		comres = p_bmg160->BMG160_BUS_READ_FUNC(p_bmg160->dev_addr,\
		BMG160_INT_2_ADDR_AWAKE_DUR__REG, &v_data_u8r, 1);
		v_data_u8r = BMG160_SET_BITSLICE(v_data_u8r,\
		BMG160_INT_2_ADDR_AWAKE_DUR, awake_dur);
		comres = p_bmg160->BMG160_BUS_WRITE_FUNC(p_bmg160->dev_addr,\
		BMG160_INT_2_ADDR_AWAKE_DUR__REG, &v_data_u8r, 1);
	}
	return comres;
}
BMG160_RETURN_FUNCTION_TYPE bmg160_get_any_dursample(unsigned char *dursample)
{
	BMG160_RETURN_FUNCTION_TYPE comres;
	unsigned char v_data_u8r;
	if (p_bmg160 == BMG160_NULL) {
		comres = E_BMG160_NULL_PTR;
	} else {
		comres = p_bmg160->BMG160_BUS_READ_FUNC(p_bmg160->dev_addr,\
		BMG160_INT_2_ADDR_ANY_DURSAMPLE__REG, &v_data_u8r, 1);
		*dursample = BMG160_GET_BITSLICE(v_data_u8r,\
		BMG160_INT_2_ADDR_ANY_DURSAMPLE);
	}
	return comres;
}
/**\brief This API is used to set Any Duration Sample
 *
 *
 *
 *
 *  \param unsigned char dursample:
 *          Value to be written passed as a parameter
 *
 *
 *
 *  \return communication results
 *
 *
 *****************************************************************************/
BMG160_RETURN_FUNCTION_TYPE bmg160_set_any_dursample(unsigned char dursample)
{
	BMG160_RETURN_FUNCTION_TYPE comres;
	unsigned char v_data_u8r;
	if (p_bmg160 == BMG160_NULL) {
		comres = E_BMG160_NULL_PTR;
	} else {
		comres = p_bmg160->BMG160_BUS_READ_FUNC(p_bmg160->dev_addr,\
		BMG160_INT_2_ADDR_ANY_DURSAMPLE__REG, &v_data_u8r, 1);
		v_data_u8r = BMG160_SET_BITSLICE(v_data_u8r,\
		BMG160_INT_2_ADDR_ANY_DURSAMPLE, dursample);
		comres = p_bmg160->BMG160_BUS_WRITE_FUNC(p_bmg160->dev_addr,\
		BMG160_INT_2_ADDR_ANY_DURSAMPLE__REG, &v_data_u8r, 1);
	}
	return comres;
}
BMG160_RETURN_FUNCTION_TYPE bmg160_get_any_en_ch(unsigned char channel,\
unsigned char *data)
{
	BMG160_RETURN_FUNCTION_TYPE comres;
	unsigned char v_data_u8r;
	if (p_bmg160 == BMG160_NULL) {
		comres = E_BMG160_NULL_PTR;
	} else {
		switch (channel) {
		case BMG160_X_AXIS:
			comres = p_bmg160->BMG160_BUS_READ_FUNC\
				(p_bmg160->dev_addr,\
			BMG160_INT_2_ADDR_ANY_EN_X__REG, &v_data_u8r, 1);
			*data = BMG160_GET_BITSLICE(v_data_u8r,\
			BMG160_INT_2_ADDR_ANY_EN_X);
			break;
		case BMG160_Y_AXIS:
			comres = p_bmg160->BMG160_BUS_READ_FUNC\
				(p_bmg160->dev_addr,\
			BMG160_INT_2_ADDR_ANY_EN_Y__REG, &v_data_u8r, 1);
			*data = BMG160_GET_BITSLICE(v_data_u8r,\
				BMG160_INT_2_ADDR_ANY_EN_Y);
			break;
		case BMG160_Z_AXIS:
			comres = p_bmg160->BMG160_BUS_READ_FUNC\
				(p_bmg160->dev_addr,\
			BMG160_INT_2_ADDR_ANY_EN_Z__REG, &v_data_u8r, 1);
			*data = BMG160_GET_BITSLICE(v_data_u8r,\
				BMG160_INT_2_ADDR_ANY_EN_Z);
			break;
		default:
			comres = E_BMG160_OUT_OF_RANGE;
			break;
		}
	}
	return comres;
}
BMG160_RETURN_FUNCTION_TYPE bmg160_set_any_en_ch(unsigned char channel,\
unsigned char data)
{
	BMG160_RETURN_FUNCTION_TYPE comres;
	unsigned char v_data_u8r;
	if (p_bmg160 == BMG160_NULL) {
		comres = E_BMG160_NULL_PTR;
	} else {
		switch (channel) {
		case BMG160_X_AXIS:
			comres = p_bmg160->BMG160_BUS_READ_FUNC\
				(p_bmg160->dev_addr,\
			BMG160_INT_2_ADDR_ANY_EN_X__REG, &v_data_u8r, 1);
			v_data_u8r = BMG160_SET_BITSLICE(v_data_u8r,\
			BMG160_INT_2_ADDR_ANY_EN_X, data);
			comres = p_bmg160->BMG160_BUS_WRITE_FUNC\
				(p_bmg160->dev_addr,\
			BMG160_INT_2_ADDR_ANY_EN_X__REG, &v_data_u8r, 1);
			break;
		case BMG160_Y_AXIS:
			comres = p_bmg160->BMG160_BUS_READ_FUNC\
				(p_bmg160->dev_addr,\
			BMG160_INT_2_ADDR_ANY_EN_Y__REG, &v_data_u8r, 1);
			v_data_u8r = BMG160_SET_BITSLICE(v_data_u8r,\
			BMG160_INT_2_ADDR_ANY_EN_Y, data);
			comres = p_bmg160->BMG160_BUS_WRITE_FUNC\
				(p_bmg160->dev_addr,\
			BMG160_INT_2_ADDR_ANY_EN_Y__REG, &v_data_u8r, 1);
			break;
		case BMG160_Z_AXIS:
			comres = p_bmg160->BMG160_BUS_READ_FUNC\
				(p_bmg160->dev_addr,\
			BMG160_INT_2_ADDR_ANY_EN_Z__REG, &v_data_u8r, 1);
			v_data_u8r = BMG160_SET_BITSLICE(v_data_u8r,\
			BMG160_INT_2_ADDR_ANY_EN_Z, data);
			comres = p_bmg160->BMG160_BUS_WRITE_FUNC\
				(p_bmg160->dev_addr,\
			BMG160_INT_2_ADDR_ANY_EN_Z__REG, &v_data_u8r, 1);
			break;
		default:
			comres = E_BMG160_OUT_OF_RANGE;
			break;
		}
	}
	return comres;
}
BMG160_RETURN_FUNCTION_TYPE bmg160_get_fifo_watermark_enable(\
unsigned char *fifo_wn_en)
{
	BMG160_RETURN_FUNCTION_TYPE comres;
	unsigned char v_data_u8r;
	if (p_bmg160 == BMG160_NULL) {
		comres = E_BMG160_NULL_PTR;
	} else {
		comres = p_bmg160->BMG160_BUS_READ_FUNC(p_bmg160->dev_addr,\
		BMG160_INT_4_FIFO_WM_EN__REG, &v_data_u8r, 1);
		*fifo_wn_en = BMG160_GET_BITSLICE(v_data_u8r,\
			BMG160_INT_4_FIFO_WM_EN);
	}
	return comres;
}
BMG160_RETURN_FUNCTION_TYPE bmg160_set_fifo_watermark_enable(\
unsigned char fifo_wn_en)
{
	BMG160_RETURN_FUNCTION_TYPE comres;
	unsigned char v_data_u8r;
	if (p_bmg160 == BMG160_NULL) {
		comres = E_BMG160_NULL_PTR;
	} else {
		if (fifo_wn_en < C_BMG160_Two_U8X) {
			comres = p_bmg160->BMG160_BUS_READ_FUNC\
				(p_bmg160->dev_addr,\
			BMG160_INT_4_FIFO_WM_EN__REG, &v_data_u8r, 1);
			v_data_u8r = BMG160_SET_BITSLICE(v_data_u8r,\
			BMG160_INT_4_FIFO_WM_EN, fifo_wn_en);
			comres = p_bmg160->BMG160_BUS_WRITE_FUNC\
				(p_bmg160->dev_addr,\
			BMG160_INT_4_FIFO_WM_EN__REG, &v_data_u8r, 1);
		} else {
			comres = E_BMG160_OUT_OF_RANGE;
		}
	}
	return comres;
}
BMG160_RETURN_FUNCTION_TYPE bmg160_set_reset_int(unsigned char reset_int)
{
	BMG160_RETURN_FUNCTION_TYPE comres;
	unsigned char v_data_u8r;
	if (p_bmg160 == BMG160_NULL) {
		comres = E_BMG160_NULL_PTR;
	} else {
		comres = p_bmg160->BMG160_BUS_READ_FUNC(p_bmg160->dev_addr,\
		BMG160_RST_LATCH_ADDR_RESET_INT__REG, &v_data_u8r, 1);
		v_data_u8r = BMG160_SET_BITSLICE(v_data_u8r,\
		BMG160_RST_LATCH_ADDR_RESET_INT, reset_int);
		comres = p_bmg160->BMG160_BUS_WRITE_FUNC(p_bmg160->dev_addr,\
		BMG160_RST_LATCH_ADDR_RESET_INT__REG, &v_data_u8r, 1);
	}
	return comres;
}
BMG160_RETURN_FUNCTION_TYPE bmg160_set_offset_reset(\
unsigned char offset_reset)
{
	BMG160_RETURN_FUNCTION_TYPE comres;
	unsigned char v_data_u8r;
	if (p_bmg160 == BMG160_NULL) {
		comres = E_BMG160_NULL_PTR;
	} else {
		comres = p_bmg160->BMG160_BUS_READ_FUNC(p_bmg160->dev_addr,\
		BMG160_RST_LATCH_ADDR_OFFSET_RESET__REG, &v_data_u8r, 1);
		v_data_u8r = BMG160_SET_BITSLICE(v_data_u8r,\
		BMG160_RST_LATCH_ADDR_OFFSET_RESET, offset_reset);
		comres = p_bmg160->BMG160_BUS_WRITE_FUNC(p_bmg160->dev_addr,\
		BMG160_RST_LATCH_ADDR_OFFSET_RESET__REG, &v_data_u8r, 1);
	}
	return comres;
}
BMG160_RETURN_FUNCTION_TYPE bmg160_get_latch_status(\
unsigned char *latch_status)
{
	BMG160_RETURN_FUNCTION_TYPE comres;
	unsigned char v_data_u8r;
	if (p_bmg160 == BMG160_NULL) {
		comres = E_BMG160_NULL_PTR;
	} else {
		comres = p_bmg160->BMG160_BUS_READ_FUNC(p_bmg160->dev_addr,\
		BMG160_RST_LATCH_ADDR_LATCH_STATUS__REG, &v_data_u8r, 1);
		*latch_status = BMG160_GET_BITSLICE(v_data_u8r,\
		BMG160_RST_LATCH_ADDR_LATCH_STATUS);
	}
	return comres;
}
/**\brief This API is used to set the Latch Status
 *
 *
 *
 *
 *  \param unsigned char latch_status:
 *          Value to be written passed as a parameter
 *
 *
 *
 *  \return communication results
 *
 *
 *****************************************************************************/
BMG160_RETURN_FUNCTION_TYPE bmg160_set_latch_status(\
unsigned char latch_status)
{
	BMG160_RETURN_FUNCTION_TYPE comres;
	unsigned char v_data_u8r;
	if (p_bmg160 == BMG160_NULL) {
		comres = E_BMG160_NULL_PTR;
	} else {
		comres = p_bmg160->BMG160_BUS_READ_FUNC(p_bmg160->dev_addr,\
		BMG160_RST_LATCH_ADDR_LATCH_STATUS__REG, &v_data_u8r, 1);
		v_data_u8r = BMG160_SET_BITSLICE(v_data_u8r,\
		BMG160_RST_LATCH_ADDR_LATCH_STATUS, latch_status);
		comres = p_bmg160->BMG160_BUS_WRITE_FUNC(p_bmg160->dev_addr,\
		BMG160_RST_LATCH_ADDR_LATCH_STATUS__REG, &v_data_u8r, 1);
	}
	return comres;
}
BMG160_RETURN_FUNCTION_TYPE bmg160_get_latch_int(unsigned char *latch_int)
{
	BMG160_RETURN_FUNCTION_TYPE comres;
	unsigned char v_data_u8r;
	if (p_bmg160 == BMG160_NULL) {
		comres = E_BMG160_NULL_PTR;
	} else {
		comres = p_bmg160->BMG160_BUS_READ_FUNC(p_bmg160->dev_addr,\
		BMG160_RST_LATCH_ADDR_LATCH_INT__REG, &v_data_u8r, 1);
		*latch_int = BMG160_GET_BITSLICE(v_data_u8r,\
		BMG160_RST_LATCH_ADDR_LATCH_INT);
	}
	return comres;
}
/**\brief This API is used to set the Latch Interrupt
 *
 *
 *
 *
 *  \param unsigned char latch_int:
 *          Value to be written passed as a parameter
 *
 *
 *
 *  \return communication results
 *
 *
 *****************************************************************************/
BMG160_RETURN_FUNCTION_TYPE bmg160_set_latch_int(unsigned char latch_int)
{
	BMG160_RETURN_FUNCTION_TYPE comres;
	unsigned char v_data_u8r;
	if (p_bmg160 == BMG160_NULL) {
		comres = E_BMG160_NULL_PTR;
	} else {
		comres = p_bmg160->BMG160_BUS_READ_FUNC(p_bmg160->dev_addr,\
		BMG160_RST_LATCH_ADDR_LATCH_INT__REG, &v_data_u8r, 1);
		v_data_u8r = BMG160_SET_BITSLICE(v_data_u8r,\
		BMG160_RST_LATCH_ADDR_LATCH_INT, latch_int);
		comres = p_bmg160->BMG160_BUS_WRITE_FUNC(p_bmg160->dev_addr,\
		BMG160_RST_LATCH_ADDR_LATCH_INT__REG, &v_data_u8r, 1);
	}
	return comres;
}
BMG160_RETURN_FUNCTION_TYPE bmg160_get_high_hy(unsigned char channel,\
unsigned char *high_hy)
{
	BMG160_RETURN_FUNCTION_TYPE comres;
	unsigned char v_data_u8r;
	if (p_bmg160 == BMG160_NULL) {
		comres = E_BMG160_NULL_PTR;
	} else {
		switch (channel) {
		case BMG160_X_AXIS:
			comres = p_bmg160->BMG160_BUS_READ_FUNC\
				(p_bmg160->dev_addr,\
			BMG160_HIGH_HY_X__REG, &v_data_u8r, 1);
			*high_hy = BMG160_GET_BITSLICE(v_data_u8r,\
				BMG160_HIGH_HY_X);
			break;
		case BMG160_Y_AXIS:
			comres = p_bmg160->BMG160_BUS_READ_FUNC\
				(p_bmg160->dev_addr,\
			BMG160_HIGH_HY_Y__REG, &v_data_u8r, 1);
			*high_hy = BMG160_GET_BITSLICE(v_data_u8r,\
				BMG160_HIGH_HY_Y);
			break;
		case BMG160_Z_AXIS:
			comres = p_bmg160->BMG160_BUS_READ_FUNC\
				(p_bmg160->dev_addr,\
			BMG160_HIGH_HY_Z__REG, &v_data_u8r, 1);
			*high_hy = BMG160_GET_BITSLICE(v_data_u8r,\
				BMG160_HIGH_HY_Z);
			break;
		default:
			comres = E_BMG160_OUT_OF_RANGE;
			break;
		}
	}
	return comres;
}
BMG160_RETURN_FUNCTION_TYPE bmg160_set_high_hy(unsigned char channel,\
unsigned char high_hy)
{
	BMG160_RETURN_FUNCTION_TYPE comres;
	unsigned char v_data_u8r;
	if (p_bmg160 == BMG160_NULL) {
		comres = E_BMG160_NULL_PTR;
	} else {
		switch (channel) {
		case BMG160_X_AXIS:
			comres = p_bmg160->BMG160_BUS_READ_FUNC\
				(p_bmg160->dev_addr,\
			BMG160_HIGH_HY_X__REG, &v_data_u8r, 1);
			v_data_u8r = BMG160_SET_BITSLICE(v_data_u8r,\
			BMG160_HIGH_HY_X, high_hy);
			comres = p_bmg160->BMG160_BUS_WRITE_FUNC\
				(p_bmg160->dev_addr,\
			BMG160_HIGH_HY_X__REG, &v_data_u8r, 1);
			break;
		case BMG160_Y_AXIS:
			comres = p_bmg160->BMG160_BUS_READ_FUNC\
				(p_bmg160->dev_addr,\
			BMG160_HIGH_HY_Y__REG, &v_data_u8r, 1);
			v_data_u8r = BMG160_SET_BITSLICE(v_data_u8r,\
			BMG160_HIGH_HY_Y, high_hy);
			comres = p_bmg160->BMG160_BUS_WRITE_FUNC\
				(p_bmg160->dev_addr,\
			BMG160_HIGH_HY_Y__REG, &v_data_u8r, 1);
			break;
		case BMG160_Z_AXIS:
			comres = p_bmg160->BMG160_BUS_READ_FUNC\
				(p_bmg160->dev_addr,\
			BMG160_HIGH_HY_Z__REG, &v_data_u8r, 1);
			v_data_u8r = BMG160_SET_BITSLICE(v_data_u8r,\
			BMG160_HIGH_HY_Z, high_hy);
			comres = p_bmg160->BMG160_BUS_WRITE_FUNC\
				(p_bmg160->dev_addr,\
			BMG160_HIGH_HY_Z__REG, &v_data_u8r, 1);
			break;
		default:
			comres = E_BMG160_OUT_OF_RANGE;
			break;
		}
	}
	return comres;
}
BMG160_RETURN_FUNCTION_TYPE bmg160_get_high_th(unsigned char channel,\
unsigned char *high_th)
{
	BMG160_RETURN_FUNCTION_TYPE comres;
	unsigned char v_data_u8r;
	if (p_bmg160 == BMG160_NULL) {
		comres = E_BMG160_NULL_PTR;
	} else {
		switch (channel) {
		case BMG160_X_AXIS:
			comres = p_bmg160->BMG160_BUS_READ_FUNC\
				(p_bmg160->dev_addr,\
			BMG160_HIGH_TH_X__REG, &v_data_u8r, 1);
			*high_th = BMG160_GET_BITSLICE(v_data_u8r,\
				BMG160_HIGH_TH_X);
			break;
		case BMG160_Y_AXIS:
			comres = p_bmg160->BMG160_BUS_READ_FUNC\
				(p_bmg160->dev_addr,\
			BMG160_HIGH_TH_Y__REG, &v_data_u8r, 1);
			*high_th = BMG160_GET_BITSLICE(v_data_u8r,\
				BMG160_HIGH_TH_Y);
			break;
		case BMG160_Z_AXIS:
			comres = p_bmg160->BMG160_BUS_READ_FUNC\
				(p_bmg160->dev_addr,\
			BMG160_HIGH_TH_Z__REG, &v_data_u8r, 1);
			*high_th = BMG160_GET_BITSLICE(v_data_u8r,\
				BMG160_HIGH_TH_Z);
			break;
		default:
			comres = E_BMG160_OUT_OF_RANGE;
			break;
		}
	}
	return comres;
}
BMG160_RETURN_FUNCTION_TYPE bmg160_set_high_th(unsigned char channel,\
unsigned char high_th)
{
	BMG160_RETURN_FUNCTION_TYPE comres;
	unsigned char v_data_u8r;
	if (p_bmg160 == BMG160_NULL) {
		comres = E_BMG160_NULL_PTR;
	} else {
		switch (channel) {
		case BMG160_X_AXIS:
			comres = p_bmg160->BMG160_BUS_READ_FUNC\
				(p_bmg160->dev_addr,\
			BMG160_HIGH_TH_X__REG, &v_data_u8r, 1);
			v_data_u8r = BMG160_SET_BITSLICE(v_data_u8r,\
				BMG160_HIGH_TH_X, high_th);
			comres = p_bmg160->BMG160_BUS_WRITE_FUNC\
				(p_bmg160->dev_addr,\
			BMG160_HIGH_TH_X__REG, &v_data_u8r, 1);
			break;
		case BMG160_Y_AXIS:
			comres = p_bmg160->BMG160_BUS_READ_FUNC\
				(p_bmg160->dev_addr,\
			BMG160_HIGH_TH_Y__REG, &v_data_u8r, 1);
			v_data_u8r = BMG160_SET_BITSLICE(v_data_u8r,\
				BMG160_HIGH_TH_Y, high_th);
			comres = p_bmg160->BMG160_BUS_WRITE_FUNC\
				(p_bmg160->dev_addr,\
			BMG160_HIGH_TH_Y__REG, &v_data_u8r, 1);
			break;
		case BMG160_Z_AXIS:
			comres = p_bmg160->BMG160_BUS_READ_FUNC\
				(p_bmg160->dev_addr,\
			BMG160_HIGH_TH_Z__REG, &v_data_u8r, 1);
			v_data_u8r = BMG160_SET_BITSLICE(v_data_u8r,\
				BMG160_HIGH_TH_Z, high_th);
			comres = p_bmg160->BMG160_BUS_WRITE_FUNC\
				(p_bmg160->dev_addr,\
			BMG160_HIGH_TH_Z__REG, &v_data_u8r, 1);
			break;
		default:
			comres = E_BMG160_OUT_OF_RANGE;
			break;
		}
	}
	return comres;
}
BMG160_RETURN_FUNCTION_TYPE bmg160_get_high_en_ch(unsigned char channel,\
unsigned char *high_en)
{
	BMG160_RETURN_FUNCTION_TYPE comres;
	unsigned char v_data_u8r;
	if (p_bmg160 == BMG160_NULL) {
		comres = E_BMG160_NULL_PTR;
	} else {
		switch (channel) {
		case BMG160_X_AXIS:
			comres = p_bmg160->BMG160_BUS_READ_FUNC\
				(p_bmg160->dev_addr,\
			BMG160_HIGH_EN_X__REG, &v_data_u8r, 1);
			*high_en = BMG160_GET_BITSLICE(v_data_u8r,\
				BMG160_HIGH_EN_X);
			break;
		case BMG160_Y_AXIS:
			comres = p_bmg160->BMG160_BUS_READ_FUNC\
				(p_bmg160->dev_addr,\
			BMG160_HIGH_EN_Y__REG, &v_data_u8r, 1);
			*high_en = BMG160_GET_BITSLICE(v_data_u8r,\
				BMG160_HIGH_EN_Y);
			break;
		case BMG160_Z_AXIS:
			comres = p_bmg160->BMG160_BUS_READ_FUNC\
				(p_bmg160->dev_addr,\
			BMG160_HIGH_EN_Z__REG, &v_data_u8r, 1);
			*high_en = BMG160_GET_BITSLICE(v_data_u8r,\
				BMG160_HIGH_EN_Z);
			break;
		default:
			comres = E_BMG160_OUT_OF_RANGE;
			break;
		}
	}
	return comres;
}
BMG160_RETURN_FUNCTION_TYPE bmg160_set_high_en_ch(unsigned char channel,\
unsigned char high_en)
{
	BMG160_RETURN_FUNCTION_TYPE comres;
	unsigned char v_data_u8r;
	if (p_bmg160 == BMG160_NULL) {
		comres = E_BMG160_NULL_PTR;
	} else {
		switch (channel) {
		case BMG160_X_AXIS:
			comres = p_bmg160->BMG160_BUS_READ_FUNC\
				(p_bmg160->dev_addr, \
			BMG160_HIGH_EN_X__REG, &v_data_u8r, 1);
			v_data_u8r = BMG160_SET_BITSLICE(v_data_u8r,\
				BMG160_HIGH_EN_X, high_en);
			comres = p_bmg160->BMG160_BUS_WRITE_FUNC\
				(p_bmg160->dev_addr,\
			BMG160_HIGH_EN_X__REG, &v_data_u8r, 1);
			break;
		case BMG160_Y_AXIS:
			comres = p_bmg160->BMG160_BUS_READ_FUNC\
				(p_bmg160->dev_addr,\
			BMG160_HIGH_EN_Y__REG, &v_data_u8r, 1);
			v_data_u8r = BMG160_SET_BITSLICE(v_data_u8r,\
				BMG160_HIGH_EN_Y, high_en);
			comres = p_bmg160->BMG160_BUS_WRITE_FUNC\
				(p_bmg160->dev_addr,\
			BMG160_HIGH_EN_Y__REG, &v_data_u8r, 1);
			break;
		case BMG160_Z_AXIS:
			comres = p_bmg160->BMG160_BUS_READ_FUNC\
				(p_bmg160->dev_addr,\
			BMG160_HIGH_EN_Z__REG, &v_data_u8r, 1);
			v_data_u8r = BMG160_SET_BITSLICE(v_data_u8r,\
				BMG160_HIGH_EN_Z, high_en);
			comres = p_bmg160->BMG160_BUS_WRITE_FUNC\
				(p_bmg160->dev_addr,\
			BMG160_HIGH_EN_Z__REG, &v_data_u8r, 1);
			break;
		default:
			comres = E_BMG160_OUT_OF_RANGE;
			break;
		}
	}
	return comres;
}
BMG160_RETURN_FUNCTION_TYPE bmg160_get_high_dur_ch(unsigned char channel,\
unsigned char *high_dur)
{
	BMG160_RETURN_FUNCTION_TYPE comres;
	unsigned char v_data_u8r;
	if (p_bmg160 == BMG160_NULL) {
		comres = E_BMG160_NULL_PTR;
	} else {
		switch (channel) {
		case BMG160_X_AXIS:
			comres = p_bmg160->BMG160_BUS_READ_FUNC\
				(p_bmg160->dev_addr,\
			BMG160_HIGH_DUR_X_ADDR, &v_data_u8r, 1);
			*high_dur = v_data_u8r;
			break;
		case BMG160_Y_AXIS:
			comres = p_bmg160->BMG160_BUS_READ_FUNC\
				(p_bmg160->dev_addr,\
			BMG160_HIGH_DUR_Y_ADDR, &v_data_u8r, 1);
			*high_dur = v_data_u8r;
			break;
		case BMG160_Z_AXIS:
			comres = p_bmg160->BMG160_BUS_READ_FUNC\
				(p_bmg160->dev_addr,\
			BMG160_HIGH_DUR_Z_ADDR, &v_data_u8r, 1);
			*high_dur = v_data_u8r;
			break;
		default:
			comres = E_BMG160_OUT_OF_RANGE;
			break;
		}
	}
	return comres;
}
/**\brief This API is used to set High Duration
 *
 *
 *
 *
 *  \param unsigned char channel,unsigned char *high_dur
 *                       channel :
 *                       BMG160_X_AXIS -> 0
 *                       BMG160_Y_AXIS -> 1
 *                       BMG160_Z_AXIS -> 2
 *                       high_dur : Value to be written passed as a parameter
 *
 *
 *
 *
 *
 *  \return communication results
 *
 *
 *****************************************************************************/
BMG160_RETURN_FUNCTION_TYPE bmg160_set_high_dur_ch(unsigned char channel,\
unsigned char high_dur)
{
	BMG160_RETURN_FUNCTION_TYPE comres;
	unsigned char v_data_u8r;
	if (p_bmg160 == BMG160_NULL) {
		comres = E_BMG160_NULL_PTR;
	} else {
		switch (channel) {
		case BMG160_X_AXIS:
			v_data_u8r = high_dur;
			comres = p_bmg160->BMG160_BUS_WRITE_FUNC\
				(p_bmg160->dev_addr,\
			BMG160_HIGH_DUR_X_ADDR, &v_data_u8r, 1);
			break;
		case BMG160_Y_AXIS:
			v_data_u8r = high_dur;
			comres = p_bmg160->BMG160_BUS_WRITE_FUNC\
				(p_bmg160->dev_addr,\
			BMG160_HIGH_DUR_Y_ADDR, &v_data_u8r, 1);
			break;
		case BMG160_Z_AXIS:
			v_data_u8r = high_dur;
			comres = p_bmg160->BMG160_BUS_WRITE_FUNC\
				(p_bmg160->dev_addr,\
			BMG160_HIGH_DUR_Z_ADDR, &v_data_u8r, 1);
			break;
		default:
			comres = E_BMG160_OUT_OF_RANGE;
			break;
		}
	}
	return comres;
}
BMG160_RETURN_FUNCTION_TYPE bmg160_get_slow_offset_th(\
unsigned char *offset_th)
{
	BMG160_RETURN_FUNCTION_TYPE comres;
	unsigned char v_data_u8r;
	if (p_bmg160 == BMG160_NULL) {
		comres = E_BMG160_NULL_PTR;
	} else {
		comres = p_bmg160->BMG160_BUS_READ_FUNC(p_bmg160->dev_addr,\
		BMG160_SLOW_OFFSET_TH__REG, &v_data_u8r, 1);
		*offset_th = BMG160_GET_BITSLICE(v_data_u8r,\
			BMG160_SLOW_OFFSET_TH);
	}
	return comres;
}
/**\brief This API is used to set Slow Offset Threshold
 *
 *
 *
 *
 *  \param unsigned char offset_th:
 *          Value to be written passed as a parameter
 *
 *
 *
 *  \return communication results
 *
 *
 *****************************************************************************/
BMG160_RETURN_FUNCTION_TYPE bmg160_set_slow_offset_th(unsigned char offset_th)
{
	BMG160_RETURN_FUNCTION_TYPE comres;
	unsigned char v_data_u8r;
	if (p_bmg160 == BMG160_NULL) {
		comres = E_BMG160_NULL_PTR;
	} else {
		comres = p_bmg160->BMG160_BUS_READ_FUNC(p_bmg160->dev_addr,\
		BMG160_SLOW_OFFSET_TH__REG, &v_data_u8r, 1);
		v_data_u8r = BMG160_SET_BITSLICE(v_data_u8r,\
		BMG160_SLOW_OFFSET_TH, offset_th);
		comres = p_bmg160->BMG160_BUS_WRITE_FUNC(p_bmg160->dev_addr,\
		BMG160_SLOW_OFFSET_TH__REG, &v_data_u8r, 1);
	}
	return comres;
}
BMG160_RETURN_FUNCTION_TYPE bmg160_get_slow_offset_dur(\
unsigned char *offset_dur)
{
	BMG160_RETURN_FUNCTION_TYPE comres;
	unsigned char v_data_u8r;
	if (p_bmg160 == BMG160_NULL) {
		comres = E_BMG160_NULL_PTR;
	} else {
		comres = p_bmg160->BMG160_BUS_READ_FUNC(p_bmg160->dev_addr,\
		BMG160_SLOW_OFFSET_DUR__REG, &v_data_u8r, 1);
		*offset_dur = BMG160_GET_BITSLICE(v_data_u8r,\
			BMG160_SLOW_OFFSET_DUR);
	}
	return comres;
}
/**\brief This API is used to set Slow Offset Duration
 *
 *
 *
 *
 *  \param unsigned char offset_dur:
 *          Value to be written passed as a parameter
 *
 *
 *
 *  \return communication results
 *
 *
 *****************************************************************************/
BMG160_RETURN_FUNCTION_TYPE bmg160_set_slow_offset_dur(\
unsigned char offset_dur)
{
	BMG160_RETURN_FUNCTION_TYPE comres;
	unsigned char v_data_u8r;
	if (p_bmg160 == BMG160_NULL) {
		comres = E_BMG160_NULL_PTR;
	} else {
		comres = p_bmg160->BMG160_BUS_READ_FUNC(p_bmg160->dev_addr,\
		BMG160_SLOW_OFFSET_DUR__REG, &v_data_u8r, 1);
		v_data_u8r = BMG160_SET_BITSLICE(v_data_u8r,\
		BMG160_SLOW_OFFSET_DUR, offset_dur);
		comres = p_bmg160->BMG160_BUS_WRITE_FUNC(p_bmg160->dev_addr,\
		BMG160_SLOW_OFFSET_DUR__REG, &v_data_u8r, 1);
	}
	return comres;
}
BMG160_RETURN_FUNCTION_TYPE bmg160_get_slow_offset_en_ch(\
unsigned char channel, unsigned char *slow_offset)
{
	BMG160_RETURN_FUNCTION_TYPE comres;
	unsigned char v_data_u8r;
	if (p_bmg160 == BMG160_NULL) {
		comres = E_BMG160_NULL_PTR;
	} else {
		switch (channel) {
		case BMG160_X_AXIS:
			comres = p_bmg160->BMG160_BUS_READ_FUNC\
				(p_bmg160->dev_addr,\
			BMG160_SLOW_OFFSET_EN_X__REG, &v_data_u8r, 1);
			*slow_offset = BMG160_GET_BITSLICE(v_data_u8r,\
			BMG160_SLOW_OFFSET_EN_X);
			break;
		case BMG160_Y_AXIS:
			comres = p_bmg160->BMG160_BUS_READ_FUNC\
				(p_bmg160->dev_addr,\
			BMG160_SLOW_OFFSET_EN_Y__REG, &v_data_u8r, 1);
			*slow_offset = BMG160_GET_BITSLICE(v_data_u8r,\
			BMG160_SLOW_OFFSET_EN_Y);
			break;
		case BMG160_Z_AXIS:
			comres = p_bmg160->BMG160_BUS_READ_FUNC\
				(p_bmg160->dev_addr,\
			BMG160_SLOW_OFFSET_EN_Z__REG, &v_data_u8r, 1);
			*slow_offset = BMG160_GET_BITSLICE(v_data_u8r,\
			BMG160_SLOW_OFFSET_EN_Z);
			break;
		default:
			comres = E_BMG160_OUT_OF_RANGE;
			break;
		}
	}
	return comres;
}
BMG160_RETURN_FUNCTION_TYPE bmg160_set_slow_offset_en_ch(\
unsigned char channel, unsigned char slow_offset)
{
	BMG160_RETURN_FUNCTION_TYPE comres;
	unsigned char v_data_u8r;
	if (p_bmg160 == BMG160_NULL) {
		comres = E_BMG160_NULL_PTR;
	} else {
		switch (channel) {
		case BMG160_X_AXIS:
			comres = p_bmg160->BMG160_BUS_READ_FUNC\
				(p_bmg160->dev_addr,\
			BMG160_SLOW_OFFSET_EN_X__REG, &v_data_u8r, 1);
			v_data_u8r = BMG160_SET_BITSLICE(v_data_u8r,\
			BMG160_SLOW_OFFSET_EN_X, slow_offset);
			comres = p_bmg160->BMG160_BUS_WRITE_FUNC\
				(p_bmg160->dev_addr,\
			BMG160_SLOW_OFFSET_EN_X__REG, &v_data_u8r, 1);
			break;
		case BMG160_Y_AXIS:
			comres = p_bmg160->BMG160_BUS_READ_FUNC\
				(p_bmg160->dev_addr,\
			BMG160_SLOW_OFFSET_EN_Y__REG, &v_data_u8r, 1);
			v_data_u8r = BMG160_SET_BITSLICE(v_data_u8r,\
			BMG160_SLOW_OFFSET_EN_Y, slow_offset);
			comres = p_bmg160->BMG160_BUS_WRITE_FUNC\
				(p_bmg160->dev_addr,\
			BMG160_SLOW_OFFSET_EN_Y__REG, &v_data_u8r, 1);
			break;
		case BMG160_Z_AXIS:
			comres = p_bmg160->BMG160_BUS_READ_FUNC\
				(p_bmg160->dev_addr,\
			BMG160_SLOW_OFFSET_EN_Z__REG, &v_data_u8r, 1);
			v_data_u8r = BMG160_SET_BITSLICE(v_data_u8r,\
				BMG160_SLOW_OFFSET_EN_Z,\
			slow_offset);
			comres = p_bmg160->BMG160_BUS_WRITE_FUNC\
				(p_bmg160->dev_addr,\
			BMG160_SLOW_OFFSET_EN_Z__REG, &v_data_u8r, 1);
			break;
		default:
			comres = E_BMG160_OUT_OF_RANGE;
			break;
		}
	}
	return comres;
}
BMG160_RETURN_FUNCTION_TYPE bmg160_get_offset_wl(unsigned char channel,\
unsigned char *offset_wl)
{
	BMG160_RETURN_FUNCTION_TYPE comres;
	unsigned char v_data_u8r;
	if (p_bmg160 == BMG160_NULL) {
		comres = E_BMG160_NULL_PTR;
	} else {
		switch (channel) {
		case BMG160_AUTO_OFFSET_WL:
			comres = p_bmg160->BMG160_BUS_READ_FUNC\
				(p_bmg160->dev_addr,\
			BMG160_AUTO_OFFSET_WL__REG, &v_data_u8r, 1);
			*offset_wl = BMG160_GET_BITSLICE(v_data_u8r,\
				BMG160_AUTO_OFFSET_WL);
			break;
		case BMG160_FAST_OFFSET_WL:
			comres = p_bmg160->BMG160_BUS_READ_FUNC\
				(p_bmg160->dev_addr,\
			BMG160_FAST_OFFSET_WL__REG, &v_data_u8r, 1);
			*offset_wl = BMG160_GET_BITSLICE(v_data_u8r,\
				BMG160_FAST_OFFSET_WL);
			break;
		default:
			comres = E_BMG160_OUT_OF_RANGE;
			break;
		}
	}
	return comres;
}
/**\brief This API is used to set Fast Offset WordLength and
 *  Auto Offset WordLength
 *
 *
 *
 *
 *  \param unsigned char channel,unsigned char *offset_wl
 *                       channel :
 *                       BMG160_AUTO_OFFSET_WL -> 0
 *                       BMG160_FAST_OFFSET_WL -> 1
 *                       offset_wl : Value to be written passed as a parameter
 *
 *
 *
 *  \return communication results
 *
 *
 *****************************************************************************/
BMG160_RETURN_FUNCTION_TYPE bmg160_set_offset_wl(\
unsigned char channel, unsigned char offset_wl)
{
	BMG160_RETURN_FUNCTION_TYPE comres;
	unsigned char v_data_u8r;
	if (p_bmg160 == BMG160_NULL) {
		comres = E_BMG160_NULL_PTR;
	} else {
		switch (channel) {
		case BMG160_AUTO_OFFSET_WL:
			comres = p_bmg160->BMG160_BUS_READ_FUNC\
				(p_bmg160->dev_addr,\
			BMG160_AUTO_OFFSET_WL__REG, &v_data_u8r, 1);
			v_data_u8r = BMG160_SET_BITSLICE(v_data_u8r,\
			BMG160_AUTO_OFFSET_WL, offset_wl);
			comres = p_bmg160->BMG160_BUS_WRITE_FUNC\
				(p_bmg160->dev_addr,\
			BMG160_AUTO_OFFSET_WL__REG, &v_data_u8r, 1);
			break;
		case BMG160_FAST_OFFSET_WL:
			comres = p_bmg160->BMG160_BUS_READ_FUNC\
				(p_bmg160->dev_addr,\
			BMG160_FAST_OFFSET_WL__REG, &v_data_u8r, 1);
			v_data_u8r = BMG160_SET_BITSLICE(v_data_u8r,\
			BMG160_FAST_OFFSET_WL, offset_wl);
			comres = p_bmg160->BMG160_BUS_WRITE_FUNC\
				(p_bmg160->dev_addr,\
			BMG160_FAST_OFFSET_WL__REG, &v_data_u8r, 1);
			break;
		default:
			comres = E_BMG160_OUT_OF_RANGE;
			break;
		}
	}
	return comres;
}
BMG160_RETURN_FUNCTION_TYPE bmg160_enable_fast_offset()
{
	BMG160_RETURN_FUNCTION_TYPE comres;
	unsigned char v_data_u8r;
	if (p_bmg160 == BMG160_NULL) {
		comres = E_BMG160_NULL_PTR;
	} else {
		comres = p_bmg160->BMG160_BUS_READ_FUNC(p_bmg160->dev_addr,\
		BMG160_FAST_OFFSET_EN__REG, &v_data_u8r, 1);
		v_data_u8r = BMG160_SET_BITSLICE(v_data_u8r,\
		BMG160_FAST_OFFSET_EN, 1);
		comres = p_bmg160->BMG160_BUS_WRITE_FUNC(p_bmg160->dev_addr,\
		BMG160_FAST_OFFSET_EN__REG, &v_data_u8r, 1);
	}
	return comres;
}
BMG160_RETURN_FUNCTION_TYPE bmg160_get_fast_offset_en_ch(\
unsigned char *fast_offset)
{
	BMG160_RETURN_FUNCTION_TYPE comres;
	unsigned char v_data_u8r;
	if (p_bmg160 == BMG160_NULL) {
		comres = E_BMG160_NULL_PTR;
	} else {
		comres = p_bmg160->BMG160_BUS_READ_FUNC\
			(p_bmg160->dev_addr,\
		BMG160_FAST_OFFSET_EN_XYZ__REG, &v_data_u8r, 1);
		*fast_offset = BMG160_GET_BITSLICE(v_data_u8r,\
			BMG160_FAST_OFFSET_EN_XYZ);
	}
	return comres;
}
BMG160_RETURN_FUNCTION_TYPE bmg160_set_fast_offset_en_ch(\
unsigned char channel, unsigned char fast_offset)
{
	BMG160_RETURN_FUNCTION_TYPE comres;
	unsigned char v_data_u8r;
	if (p_bmg160 == BMG160_NULL) {
		comres = E_BMG160_NULL_PTR;
	} else {
		switch (channel) {
		case BMG160_X_AXIS:
			comres = p_bmg160->BMG160_BUS_READ_FUNC\
				(p_bmg160->dev_addr,\
			BMG160_FAST_OFFSET_EN_X__REG, &v_data_u8r, 1);
			v_data_u8r = BMG160_SET_BITSLICE(v_data_u8r,\
			BMG160_FAST_OFFSET_EN_X, fast_offset);
			comres = p_bmg160->BMG160_BUS_WRITE_FUNC\
				(p_bmg160->dev_addr,\
			BMG160_FAST_OFFSET_EN_X__REG, &v_data_u8r, 1);
			break;
		case BMG160_Y_AXIS:
			comres = p_bmg160->BMG160_BUS_READ_FUNC\
				(p_bmg160->dev_addr,\
			BMG160_FAST_OFFSET_EN_Y__REG, &v_data_u8r, 1);
			v_data_u8r = BMG160_SET_BITSLICE(v_data_u8r,\
			BMG160_FAST_OFFSET_EN_Y, fast_offset);
			comres = p_bmg160->BMG160_BUS_WRITE_FUNC\
				(p_bmg160->dev_addr,\
			BMG160_FAST_OFFSET_EN_Y__REG, &v_data_u8r, 1);
			break;
		case BMG160_Z_AXIS:
			comres = p_bmg160->BMG160_BUS_READ_FUNC\
				(p_bmg160->dev_addr,\
			BMG160_FAST_OFFSET_EN_Z__REG, &v_data_u8r, 1);
			v_data_u8r = BMG160_SET_BITSLICE(v_data_u8r,\
			BMG160_FAST_OFFSET_EN_Z, fast_offset);
			comres = p_bmg160->BMG160_BUS_WRITE_FUNC\
				(p_bmg160->dev_addr,\
			BMG160_FAST_OFFSET_EN_Z__REG, &v_data_u8r, 1);
			break;
		default:
			comres = E_BMG160_OUT_OF_RANGE;
			break;
		}
	}
	return comres;
}
BMG160_RETURN_FUNCTION_TYPE bmg160_get_nvm_remain(unsigned char *nvm_remain)
{
	BMG160_RETURN_FUNCTION_TYPE comres;
	unsigned char v_data_u8r;
	if (p_bmg160 == BMG160_NULL) {
		comres = E_BMG160_NULL_PTR;
	} else {
		comres = p_bmg160->BMG160_BUS_READ_FUNC(p_bmg160->dev_addr,\
		BMG160_TRIM_NVM_CTRL_ADDR_NVM_REMAIN__REG, &v_data_u8r, 1);
		*nvm_remain = BMG160_GET_BITSLICE(v_data_u8r,\
		BMG160_TRIM_NVM_CTRL_ADDR_NVM_REMAIN);
	}
	return comres;
}
BMG160_RETURN_FUNCTION_TYPE bmg160_set_nvm_load(unsigned char nvm_load)
{
	BMG160_RETURN_FUNCTION_TYPE comres;
	unsigned char v_data_u8r;
	if (p_bmg160 == BMG160_NULL) {
		comres = E_BMG160_NULL_PTR;
	} else {
		comres = p_bmg160->BMG160_BUS_READ_FUNC(p_bmg160->dev_addr,\
		BMG160_TRIM_NVM_CTRL_ADDR_NVM_LOAD__REG, &v_data_u8r, 1);
		v_data_u8r = BMG160_SET_BITSLICE(v_data_u8r,\
		BMG160_TRIM_NVM_CTRL_ADDR_NVM_LOAD, nvm_load);
		comres = p_bmg160->BMG160_BUS_WRITE_FUNC(p_bmg160->dev_addr,\
		BMG160_TRIM_NVM_CTRL_ADDR_NVM_LOAD__REG, &v_data_u8r, 1);
	}
	return comres;
}
BMG160_RETURN_FUNCTION_TYPE bmg160_get_nvm_rdy(unsigned char *nvm_rdy)
{
	BMG160_RETURN_FUNCTION_TYPE comres;
	unsigned char v_data_u8r;
	if (p_bmg160 == BMG160_NULL) {
		comres = E_BMG160_NULL_PTR;
	} else {
		comres = p_bmg160->BMG160_BUS_READ_FUNC(p_bmg160->dev_addr,\
		BMG160_TRIM_NVM_CTRL_ADDR_NVM_RDY__REG, &v_data_u8r, 1);
		*nvm_rdy = BMG160_GET_BITSLICE(v_data_u8r,\
		BMG160_TRIM_NVM_CTRL_ADDR_NVM_RDY);
	}
	return comres;
}
BMG160_RETURN_FUNCTION_TYPE bmg160_set_nvm_prog_trig(unsigned char prog_trig)
{
	BMG160_RETURN_FUNCTION_TYPE comres;
	unsigned char v_data_u8r;
	if (p_bmg160 == BMG160_NULL) {
		comres = E_BMG160_NULL_PTR;
	} else {
		comres = p_bmg160->BMG160_BUS_READ_FUNC(p_bmg160->dev_addr,\
		BMG160_TRIM_NVM_CTRL_ADDR_NVM_PROG_TRIG__REG, &v_data_u8r, 1);
		v_data_u8r = BMG160_SET_BITSLICE(v_data_u8r,\
		BMG160_TRIM_NVM_CTRL_ADDR_NVM_PROG_TRIG, prog_trig);
		comres = p_bmg160->BMG160_BUS_WRITE_FUNC(p_bmg160->dev_addr,\
		BMG160_TRIM_NVM_CTRL_ADDR_NVM_PROG_TRIG__REG, &v_data_u8r, 1);
	}
	return comres;
}
BMG160_RETURN_FUNCTION_TYPE bmg160_get_nvm_prog_mode(unsigned char *prog_mode)
{
	BMG160_RETURN_FUNCTION_TYPE comres;
	unsigned char v_data_u8r;
	if (p_bmg160 == BMG160_NULL) {
		comres = E_BMG160_NULL_PTR;
	} else {
		comres = p_bmg160->BMG160_BUS_READ_FUNC(p_bmg160->dev_addr,\
		BMG160_TRIM_NVM_CTRL_ADDR_NVM_PROG_MODE__REG, &v_data_u8r, 1);
		*prog_mode = BMG160_GET_BITSLICE(v_data_u8r,\
		BMG160_TRIM_NVM_CTRL_ADDR_NVM_PROG_MODE);
	}
	return comres;
}
BMG160_RETURN_FUNCTION_TYPE bmg160_set_nvm_prog_mode(unsigned char prog_mode)
{
	BMG160_RETURN_FUNCTION_TYPE comres;
	unsigned char v_data_u8r;
	if (p_bmg160 == BMG160_NULL) {
		comres = E_BMG160_NULL_PTR;
	} else {
		comres = p_bmg160->BMG160_BUS_READ_FUNC(p_bmg160->dev_addr,\
		BMG160_TRIM_NVM_CTRL_ADDR_NVM_PROG_MODE__REG, &v_data_u8r, 1);
		v_data_u8r = BMG160_SET_BITSLICE(v_data_u8r,\
		BMG160_TRIM_NVM_CTRL_ADDR_NVM_PROG_MODE, prog_mode);
		comres = p_bmg160->BMG160_BUS_WRITE_FUNC(p_bmg160->dev_addr,\
		BMG160_TRIM_NVM_CTRL_ADDR_NVM_PROG_MODE__REG, &v_data_u8r, 1);
	}
	return comres;
}
BMG160_RETURN_FUNCTION_TYPE bmg160_get_i2c_wdt(unsigned char i2c_wdt,\
unsigned char *prog_mode)
{
	BMG160_RETURN_FUNCTION_TYPE comres;
	unsigned char v_data_u8r;
	if (p_bmg160 == BMG160_NULL) {
		comres = E_BMG160_NULL_PTR;
	} else {
		switch (i2c_wdt) {
		case BMG160_I2C_WDT_EN:
			comres = p_bmg160->BMG160_BUS_READ_FUNC\
				(p_bmg160->dev_addr,\
			BMG160_BGW_SPI3_WDT_ADDR_I2C_WDT_EN__REG,\
			&v_data_u8r, 1);
			*prog_mode = BMG160_GET_BITSLICE(v_data_u8r,\
			BMG160_BGW_SPI3_WDT_ADDR_I2C_WDT_EN);
			break;
		case BMG160_I2C_WDT_SEL:
			comres = p_bmg160->BMG160_BUS_READ_FUNC\
				(p_bmg160->dev_addr,\
			BMG160_BGW_SPI3_WDT_ADDR_I2C_WDT_SEL__REG,\
			&v_data_u8r, 1);
			*prog_mode = BMG160_GET_BITSLICE(v_data_u8r,\
			BMG160_BGW_SPI3_WDT_ADDR_I2C_WDT_SEL);
			break;
		default:
			comres = E_BMG160_OUT_OF_RANGE;
			break;
		}
	}
	return comres;
}
/**\brief This API is used to set the status of i2c wdt
 *
 *
 *
 *
 *  \param unsigned char channel,unsigned char prog_mode
 *            BMG160_I2C_WDT_SEL               1
 *            BMG160_I2C_WDT_EN                0
 *            prog_mode : Value to be written passed as a parameter
 *
 *
 *
 *  \return communication results
 *
 *
 *****************************************************************************/
BMG160_RETURN_FUNCTION_TYPE bmg160_set_i2c_wdt(unsigned char i2c_wdt,\
unsigned char prog_mode)
{
	BMG160_RETURN_FUNCTION_TYPE comres;
	unsigned char v_data_u8r;
	if (p_bmg160 == BMG160_NULL) {
		comres = E_BMG160_NULL_PTR;
	} else {
		switch (i2c_wdt) {
		case BMG160_I2C_WDT_EN:
			comres = p_bmg160->BMG160_BUS_READ_FUNC\
				(p_bmg160->dev_addr,\
			BMG160_BGW_SPI3_WDT_ADDR_I2C_WDT_EN__REG,\
			&v_data_u8r, 1);
			v_data_u8r = BMG160_SET_BITSLICE(v_data_u8r,\
			BMG160_BGW_SPI3_WDT_ADDR_I2C_WDT_EN, prog_mode);
			comres = p_bmg160->BMG160_BUS_WRITE_FUNC\
				(p_bmg160->dev_addr,\
			BMG160_BGW_SPI3_WDT_ADDR_I2C_WDT_EN__REG,\
			&v_data_u8r, 1);
			break;
		case BMG160_I2C_WDT_SEL:
			comres = p_bmg160->BMG160_BUS_READ_FUNC\
				(p_bmg160->dev_addr,\
			BMG160_BGW_SPI3_WDT_ADDR_I2C_WDT_SEL__REG,\
			&v_data_u8r, 1);
			v_data_u8r = BMG160_SET_BITSLICE(v_data_u8r,\
			BMG160_BGW_SPI3_WDT_ADDR_I2C_WDT_SEL, prog_mode);
			comres = p_bmg160->BMG160_BUS_WRITE_FUNC\
				(p_bmg160->dev_addr,\
			BMG160_BGW_SPI3_WDT_ADDR_I2C_WDT_SEL__REG,\
			&v_data_u8r, 1);
			break;
		default:
			comres = E_BMG160_OUT_OF_RANGE;
			break;
		}
	}
	return comres;
}
BMG160_RETURN_FUNCTION_TYPE bmg160_get_spi3(unsigned char *spi3)
{
	BMG160_RETURN_FUNCTION_TYPE comres;
	unsigned char v_data_u8r;
	if (p_bmg160 == BMG160_NULL) {
		comres = E_BMG160_NULL_PTR;
	} else {
		comres = p_bmg160->BMG160_BUS_READ_FUNC(p_bmg160->dev_addr,\
		BMG160_BGW_SPI3_WDT_ADDR_SPI3__REG, &v_data_u8r, 1);
		*spi3 = BMG160_GET_BITSLICE(v_data_u8r,\
			BMG160_BGW_SPI3_WDT_ADDR_SPI3);
	}
	return comres;
}
BMG160_RETURN_FUNCTION_TYPE bmg160_set_spi3(unsigned char spi3)
{
	BMG160_RETURN_FUNCTION_TYPE comres;
	unsigned char v_data_u8r;
	if (p_bmg160 == BMG160_NULL) {
		comres = E_BMG160_NULL_PTR;
	} else {
		comres = p_bmg160->BMG160_BUS_READ_FUNC(p_bmg160->dev_addr,\
		BMG160_BGW_SPI3_WDT_ADDR_SPI3__REG, &v_data_u8r, 1);
		v_data_u8r = BMG160_SET_BITSLICE(v_data_u8r,\
		BMG160_BGW_SPI3_WDT_ADDR_SPI3, spi3);
		comres = p_bmg160->BMG160_BUS_WRITE_FUNC(p_bmg160->dev_addr,\
		BMG160_BGW_SPI3_WDT_ADDR_SPI3__REG, &v_data_u8r, 1);
	}
	return comres;
}
BMG160_RETURN_FUNCTION_TYPE bmg160_get_fifo_tag(unsigned char *tag)
{
	BMG160_RETURN_FUNCTION_TYPE comres;
	unsigned char v_data_u8r;
	if (p_bmg160 == BMG160_NULL) {
		comres = E_BMG160_NULL_PTR;
	} else {
		comres = p_bmg160->BMG160_BUS_READ_FUNC(p_bmg160->dev_addr,\
		BMG160_FIFO_CGF1_ADDR_TAG__REG, &v_data_u8r, 1);
		*tag = BMG160_GET_BITSLICE(v_data_u8r,\
			BMG160_FIFO_CGF1_ADDR_TAG);
	}
	return comres;
}
BMG160_RETURN_FUNCTION_TYPE bmg160_set_fifo_tag(unsigned char tag)
{
	BMG160_RETURN_FUNCTION_TYPE comres;
	unsigned char v_data_u8r;
	if (p_bmg160 == BMG160_NULL) {
		comres = E_BMG160_NULL_PTR;
	} else {
		if (tag < C_BMG160_Two_U8X) {
			comres = p_bmg160->BMG160_BUS_READ_FUNC\
				(p_bmg160->dev_addr,\
			BMG160_FIFO_CGF1_ADDR_TAG__REG, &v_data_u8r, 1);
			v_data_u8r = BMG160_SET_BITSLICE(v_data_u8r,\
			BMG160_FIFO_CGF1_ADDR_TAG, tag);
			comres = p_bmg160->BMG160_BUS_WRITE_FUNC\
				(p_bmg160->dev_addr,\
			BMG160_FIFO_CGF1_ADDR_TAG__REG, &v_data_u8r, 1);
		} else {
			comres = E_BMG160_OUT_OF_RANGE;
		}
	}
	return comres;
}
BMG160_RETURN_FUNCTION_TYPE bmg160_get_fifo_watermarklevel(\
unsigned char *water_mark_level)
{
	BMG160_RETURN_FUNCTION_TYPE comres;
	unsigned char v_data_u8r;
	if (p_bmg160 == BMG160_NULL) {
		comres = E_BMG160_NULL_PTR;
	} else {
		comres = p_bmg160->BMG160_BUS_READ_FUNC(p_bmg160->dev_addr,\
		BMG160_FIFO_CGF1_ADDR_WML__REG, &v_data_u8r, 1);
		*water_mark_level = BMG160_GET_BITSLICE(v_data_u8r,\
		BMG160_FIFO_CGF1_ADDR_WML);
	}
	return comres;
}
/**\brief This API is used to set Water Mark Level
 *
 *
 *
 *
 *  \param unsigned char water_mark_level:
 *          Value to be written passed as a parameter

 *
 *
 *
 *  \return communication results
 *
 *
 *****************************************************************************/
BMG160_RETURN_FUNCTION_TYPE bmg160_set_fifo_watermarklevel(\
unsigned char water_mark_level)
{
	BMG160_RETURN_FUNCTION_TYPE comres;
	unsigned char v_data_u8r;
	if (p_bmg160 == BMG160_NULL) {
		comres = E_BMG160_NULL_PTR;
	} else {
		if (water_mark_level < C_BMG160_OneTwentyEight_U8X) {
			comres = p_bmg160->BMG160_BUS_READ_FUNC\
				(p_bmg160->dev_addr,\
			BMG160_FIFO_CGF1_ADDR_WML__REG, &v_data_u8r, 1);
			v_data_u8r = BMG160_SET_BITSLICE(v_data_u8r,\
			BMG160_FIFO_CGF1_ADDR_WML, water_mark_level);
			comres = p_bmg160->BMG160_BUS_WRITE_FUNC\
				(p_bmg160->dev_addr,\
			BMG160_FIFO_CGF1_ADDR_WML__REG, &v_data_u8r, 1);
		} else {
			comres = E_BMG160_OUT_OF_RANGE;
		}
	}
	return comres;
}
BMG160_RETURN_FUNCTION_TYPE bmg160_get_offset(unsigned char axis,\
BMG160_S16 *offset)
{
	BMG160_RETURN_FUNCTION_TYPE comres;
	unsigned char v_data1_u8r, v_data2_u8r;
	if (p_bmg160 == BMG160_NULL) {
		comres = E_BMG160_NULL_PTR;
	} else {
		switch (axis) {
		case BMG160_X_AXIS:
			comres = p_bmg160->BMG160_BUS_READ_FUNC\
				(p_bmg160->dev_addr,\
			BMG160_TRIM_GP0_ADDR_OFFSET_X__REG, &v_data1_u8r, 1);
			v_data1_u8r = BMG160_GET_BITSLICE(v_data1_u8r,\
			BMG160_TRIM_GP0_ADDR_OFFSET_X);
			comres = p_bmg160->BMG160_BUS_READ_FUNC\
				(p_bmg160->dev_addr,\
			BMG160_OFC1_ADDR_OFFSET_X__REG, &v_data2_u8r, 1);
			v_data2_u8r = BMG160_GET_BITSLICE(v_data2_u8r,\
			BMG160_OFC1_ADDR_OFFSET_X);
			v_data2_u8r = ((v_data2_u8r <<\
			BMG160_SHIFT_2_POSITION) | v_data1_u8r);
			comres = p_bmg160->BMG160_BUS_READ_FUNC\
			(p_bmg160->dev_addr, BMG160_OFC2_ADDR, &v_data1_u8r, 1);
			*offset = (BMG160_S16)((((BMG160_S16)\
				((signed char)v_data1_u8r))\
			<< BMG160_SHIFT_4_POSITION) | (v_data2_u8r));
			break;
		case BMG160_Y_AXIS:
			comres = p_bmg160->BMG160_BUS_READ_FUNC\
				(p_bmg160->dev_addr,\
			BMG160_TRIM_GP0_ADDR_OFFSET_Y__REG, &v_data1_u8r, 1);
			v_data1_u8r = BMG160_GET_BITSLICE(v_data1_u8r,\
			BMG160_TRIM_GP0_ADDR_OFFSET_Y);
			comres = p_bmg160->BMG160_BUS_READ_FUNC\
				(p_bmg160->dev_addr,\
			BMG160_OFC1_ADDR_OFFSET_Y__REG, &v_data2_u8r, 1);
			v_data2_u8r = BMG160_GET_BITSLICE(v_data2_u8r,\
			BMG160_OFC1_ADDR_OFFSET_Y);
			v_data2_u8r = ((v_data2_u8r << \
			BMG160_SHIFT_1_POSITION) | v_data1_u8r);
			comres = p_bmg160->BMG160_BUS_READ_FUNC\
				(p_bmg160->dev_addr,\
			BMG160_OFC3_ADDR, &v_data1_u8r, 1);
			*offset = (BMG160_S16)((((BMG160_S16)\
				((signed char)v_data1_u8r))\
			<< BMG160_SHIFT_4_POSITION) | (v_data2_u8r));
			break;
		case BMG160_Z_AXIS:
			comres = p_bmg160->BMG160_BUS_READ_FUNC\
				(p_bmg160->dev_addr,\
			BMG160_TRIM_GP0_ADDR_OFFSET_Z__REG, &v_data1_u8r, 1);
			v_data1_u8r = BMG160_GET_BITSLICE(v_data1_u8r,\
			BMG160_TRIM_GP0_ADDR_OFFSET_Z);
			comres = p_bmg160->BMG160_BUS_READ_FUNC\
				(p_bmg160->dev_addr,\
			BMG160_OFC1_ADDR_OFFSET_Z__REG, &v_data2_u8r, 1);
			v_data2_u8r = BMG160_GET_BITSLICE(v_data2_u8r,\
			BMG160_OFC1_ADDR_OFFSET_Z);
			v_data2_u8r = ((v_data2_u8r << BMG160_SHIFT_1_POSITION)\
				| v_data1_u8r);
			comres = p_bmg160->BMG160_BUS_READ_FUNC\
				(p_bmg160->dev_addr,\
			BMG160_OFC4_ADDR, &v_data1_u8r, 1);
			*offset = (BMG160_S16)((((BMG160_S16)\
				((signed char)v_data1_u8r))\
			<< BMG160_SHIFT_4_POSITION) | (v_data2_u8r));
			break;
		default:
			comres = E_BMG160_OUT_OF_RANGE;
			break;
		}
	}
	return comres;
}
BMG160_RETURN_FUNCTION_TYPE bmg160_set_offset(\
unsigned char axis, BMG160_S16 offset)
{
	BMG160_RETURN_FUNCTION_TYPE comres;
	unsigned char v_data1_u8r, v_data2_u8r;
	if (p_bmg160 == BMG160_NULL) {
		comres = E_BMG160_NULL_PTR;
	} else {
		switch (axis) {
		case BMG160_X_AXIS:
			v_data1_u8r = ((signed char) (offset & 0x0FF0))\
			>> BMG160_SHIFT_4_POSITION;
			comres = p_bmg160->BMG160_BUS_WRITE_FUNC\
				(p_bmg160->dev_addr,\
			BMG160_OFC2_ADDR, &v_data1_u8r, 1);

			v_data1_u8r = (unsigned char) (offset & 0x000C);
			v_data2_u8r = BMG160_SET_BITSLICE(v_data2_u8r,\
			BMG160_OFC1_ADDR_OFFSET_X, v_data1_u8r);
			comres = p_bmg160->BMG160_BUS_READ_FUNC\
				(p_bmg160->dev_addr,\
			BMG160_OFC1_ADDR_OFFSET_X__REG, &v_data2_u8r, 1);

			v_data1_u8r = (unsigned char) (offset & 0x0003);
			v_data2_u8r = BMG160_SET_BITSLICE(v_data2_u8r,\
			BMG160_TRIM_GP0_ADDR_OFFSET_X, v_data1_u8r);
			comres = p_bmg160->BMG160_BUS_WRITE_FUNC\
				(p_bmg160->dev_addr,\
			BMG160_TRIM_GP0_ADDR_OFFSET_X__REG, &v_data2_u8r, 1);
			break;
		case BMG160_Y_AXIS:
			v_data1_u8r = ((signed char) (offset & 0x0FF0)) >>\
			BMG160_SHIFT_4_POSITION;
			comres = p_bmg160->BMG160_BUS_WRITE_FUNC\
				(p_bmg160->dev_addr,\
			BMG160_OFC3_ADDR, &v_data1_u8r, 1);

			v_data1_u8r = (unsigned char) (offset & 0x000E);
			v_data2_u8r = BMG160_SET_BITSLICE(v_data2_u8r,\
			BMG160_OFC1_ADDR_OFFSET_Y, v_data1_u8r);
			comres = p_bmg160->BMG160_BUS_READ_FUNC\
				(p_bmg160->dev_addr,\
			BMG160_OFC1_ADDR_OFFSET_Y__REG, &v_data2_u8r, 1);

			v_data1_u8r = (unsigned char) (offset & 0x0001);
			v_data2_u8r = BMG160_SET_BITSLICE(v_data2_u8r,\
			BMG160_TRIM_GP0_ADDR_OFFSET_Y, v_data1_u8r);
			comres = p_bmg160->BMG160_BUS_WRITE_FUNC\
				(p_bmg160->dev_addr,\
			BMG160_TRIM_GP0_ADDR_OFFSET_Y__REG, &v_data2_u8r, 1);
			break;
		case BMG160_Z_AXIS:
			v_data1_u8r = ((signed char) (offset & 0x0FF0)) >>\
			BMG160_SHIFT_4_POSITION;
			comres = p_bmg160->BMG160_BUS_WRITE_FUNC\
				(p_bmg160->dev_addr,\
			BMG160_OFC4_ADDR, &v_data1_u8r, 1);

			v_data1_u8r = (unsigned char) (offset & 0x000E);
			v_data2_u8r = BMG160_SET_BITSLICE(v_data2_u8r,\
			BMG160_OFC1_ADDR_OFFSET_Z, v_data1_u8r);
			comres = p_bmg160->BMG160_BUS_READ_FUNC\
				(p_bmg160->dev_addr,\
			BMG160_OFC1_ADDR_OFFSET_Z__REG, &v_data2_u8r, 1);

			v_data1_u8r = (unsigned char) (offset & 0x0001);
			v_data2_u8r = BMG160_SET_BITSLICE(v_data2_u8r,\
			BMG160_TRIM_GP0_ADDR_OFFSET_Z, v_data1_u8r);
			comres = p_bmg160->BMG160_BUS_WRITE_FUNC\
				(p_bmg160->dev_addr,\
			BMG160_TRIM_GP0_ADDR_OFFSET_Z__REG, &v_data2_u8r, 1);
			break;
		default:
			comres = E_BMG160_OUT_OF_RANGE;
			break;
		}
	}
	return comres;
}
BMG160_RETURN_FUNCTION_TYPE bmg160_get_gp(unsigned char param,\
unsigned char *value)
{
	BMG160_RETURN_FUNCTION_TYPE comres;
	unsigned char v_data_u8r;
	if (p_bmg160 == BMG160_NULL) {
		comres = E_BMG160_NULL_PTR;
	} else {
		switch (param) {
		case BMG160_GP0:
			comres = p_bmg160->BMG160_BUS_READ_FUNC\
				(p_bmg160->dev_addr,\
			BMG160_TRIM_GP0_ADDR_GP0__REG, &v_data_u8r, 1);
			*value = BMG160_GET_BITSLICE(v_data_u8r,\
				BMG160_TRIM_GP0_ADDR_GP0);
			break;
		case BMG160_GP1:
			comres = p_bmg160->BMG160_BUS_READ_FUNC\
				(p_bmg160->dev_addr,\
			BMG160_TRIM_GP1_ADDR, &v_data_u8r, 1);
			*value = v_data_u8r;
			break;
		default:
			comres = E_BMG160_OUT_OF_RANGE;
			break;
		}
	}
	return comres;
}
/**\brief This API is used to set the status of general
 * purpose register
 *
 *
 *
 *
 *  \param unsigned char param,unsigned char value
 *             param ->
 *              BMG160_GP0                      0
 *              BMG160_GP0                      1
 *             value -> Value to be written passed as a parameter
 *
 *
 *
 *  \return communication results
 *
 *
 *****************************************************************************/
BMG160_RETURN_FUNCTION_TYPE bmg160_set_gp(unsigned char param,\
unsigned char value)
{
	BMG160_RETURN_FUNCTION_TYPE comres;
	unsigned char v_data_u8r;
	if (p_bmg160 == BMG160_NULL) {
		comres = E_BMG160_NULL_PTR;
	} else {
		switch (param) {
		case BMG160_GP0:
			comres = p_bmg160->BMG160_BUS_READ_FUNC\
				(p_bmg160->dev_addr,\
			BMG160_TRIM_GP0_ADDR_GP0__REG, &v_data_u8r, 1);
			v_data_u8r = BMG160_SET_BITSLICE(v_data_u8r,\
			BMG160_TRIM_GP0_ADDR_GP0, value);
			comres = p_bmg160->BMG160_BUS_WRITE_FUNC\
				(p_bmg160->dev_addr,\
			BMG160_TRIM_GP0_ADDR_GP0__REG, &v_data_u8r, 1);
			break;
		case BMG160_GP1:
			v_data_u8r = value;
			comres = p_bmg160->BMG160_BUS_WRITE_FUNC\
				(p_bmg160->dev_addr,\
			BMG160_TRIM_GP1_ADDR, &v_data_u8r, 1);
			break;
		default:
			comres = E_BMG160_OUT_OF_RANGE;
			break;
		}
	}
	return comres;
}
BMG160_RETURN_FUNCTION_TYPE bmg160_get_FIFO_data_reg(unsigned char *FIFO_data)
{
	BMG160_RETURN_FUNCTION_TYPE comres;
	unsigned char v_data_u8r;
	if (p_bmg160 == BMG160_NULL) {
		comres = E_BMG160_NULL_PTR;
	} else {
		comres = p_bmg160->BMG160_BUS_READ_FUNC(p_bmg160->dev_addr,\
		BMG160_FIFO_DATA_ADDR, &v_data_u8r, 1);
		*FIFO_data = v_data_u8r;
	}
	return comres;
}

BMG160_RETURN_FUNCTION_TYPE bmg160_get_fifostatus_reg( \
unsigned char *fifo_status)
{
	BMG160_RETURN_FUNCTION_TYPE comres;
	if (p_bmg160 == BMG160_NULL) {
		comres = E_BMG160_NULL_PTR;
	} else {
		comres = p_bmg160->BMG160_BUS_READ_FUNC(p_bmg160->dev_addr,\
		BMG160_FIFO_STATUS_ADDR, fifo_status, 1);
	}
	return comres;
}

BMG160_RETURN_FUNCTION_TYPE bmg160_get_fifo_framecount( \
unsigned char *fifo_framecount)
{
	BMG160_RETURN_FUNCTION_TYPE comres;
	unsigned char v_data_u8r;
	if (p_bmg160 == BMG160_NULL) {
		comres = E_BMG160_NULL_PTR;
	} else {
		comres = p_bmg160->BMG160_BUS_READ_FUNC(p_bmg160->dev_addr,\
		BMG160_FIFO_STATUS_FRAME_COUNTER__REG, &v_data_u8r, 1);
		*fifo_framecount = BMG160_GET_BITSLICE(v_data_u8r,\
		BMG160_FIFO_STATUS_FRAME_COUNTER);
	}
	return comres;
}

BMG160_RETURN_FUNCTION_TYPE bmg160_get_fifo_overrun( \
unsigned char *fifo_overrun)
{
	BMG160_RETURN_FUNCTION_TYPE comres;
	unsigned char v_data_u8r;
	if (p_bmg160 == BMG160_NULL) {
		comres = E_BMG160_NULL_PTR;
	} else {
		comres = p_bmg160->BMG160_BUS_READ_FUNC(p_bmg160->dev_addr,\
		BMG160_FIFO_STATUS_OVERRUN__REG, &v_data_u8r, 1);
		*fifo_overrun = BMG160_GET_BITSLICE(v_data_u8r,\
		BMG160_FIFO_STATUS_OVERRUN);
	}
	return comres;
}
BMG160_RETURN_FUNCTION_TYPE bmg160_get_fifo_mode(unsigned char *mode)
{
	BMG160_RETURN_FUNCTION_TYPE comres;
	unsigned char v_data_u8r;
	if (p_bmg160 == BMG160_NULL) {
		comres = E_BMG160_NULL_PTR;
	} else {
		comres = p_bmg160->BMG160_BUS_READ_FUNC(p_bmg160->dev_addr,\
		BMG160_FIFO_CGF0_ADDR_MODE__REG, &v_data_u8r, 1);
		*mode = BMG160_GET_BITSLICE(v_data_u8r,\
			BMG160_FIFO_CGF0_ADDR_MODE);
	}
	return comres;
}
BMG160_RETURN_FUNCTION_TYPE bmg160_set_fifo_mode(unsigned char mode)
{
	int comres = C_BMG160_Zero_U8X;
	unsigned char v_data_u8r;
	if (p_bmg160 == BMG160_NULL) {
		comres = E_BMG160_NULL_PTR;
	} else {
		if (mode < C_BMG160_Four_U8X) {
			comres = p_bmg160->BMG160_BUS_READ_FUNC\
				(p_bmg160->dev_addr,\
			BMG160_FIFO_CGF0_ADDR_MODE__REG, &v_data_u8r, 1);
			v_data_u8r = BMG160_SET_BITSLICE(v_data_u8r,\
			BMG160_FIFO_CGF0_ADDR_MODE, mode);
			comres = p_bmg160->BMG160_BUS_WRITE_FUNC\
				(p_bmg160->dev_addr,\
			BMG160_FIFO_CGF0_ADDR_MODE__REG, &v_data_u8r, 1);
		} else {
			comres = E_BMG160_OUT_OF_RANGE;
		}
	}
	return comres;
}
BMG160_RETURN_FUNCTION_TYPE bmg160_get_fifo_data_sel(unsigned char *data_sel)
{
	BMG160_RETURN_FUNCTION_TYPE comres;
	unsigned char v_data_u8r;
	if (p_bmg160 == BMG160_NULL) {
		comres = E_BMG160_NULL_PTR;
	} else {
		comres = p_bmg160->BMG160_BUS_READ_FUNC(p_bmg160->dev_addr,\
		BMG160_FIFO_CGF0_ADDR_DATA_SEL__REG, &v_data_u8r, 1);
		*data_sel = BMG160_GET_BITSLICE(v_data_u8r,\
		BMG160_FIFO_CGF0_ADDR_DATA_SEL);
	}
	return comres;
}
BMG160_RETURN_FUNCTION_TYPE bmg160_set_fifo_data_sel(unsigned char data_sel)
{
	BMG160_RETURN_FUNCTION_TYPE comres;
	unsigned char v_data_u8r;
	if (p_bmg160 == BMG160_NULL) {
		comres = E_BMG160_NULL_PTR;
	} else {
		if (data_sel < C_BMG160_Four_U8X) {
			comres = p_bmg160->BMG160_BUS_READ_FUNC\
				(p_bmg160->dev_addr,\
			BMG160_FIFO_CGF0_ADDR_DATA_SEL__REG, &v_data_u8r, 1);
			v_data_u8r = BMG160_SET_BITSLICE(v_data_u8r,\
			BMG160_FIFO_CGF0_ADDR_DATA_SEL, data_sel);
			comres = p_bmg160->BMG160_BUS_WRITE_FUNC\
				(p_bmg160->dev_addr,\
			BMG160_FIFO_CGF0_ADDR_DATA_SEL__REG, &v_data_u8r, 1);
		} else {
			comres = E_BMG160_OUT_OF_RANGE;
		}
	}
	return comres;
}
BMG160_RETURN_FUNCTION_TYPE bmg160_get_mode(unsigned char *Mode)
{
	BMG160_RETURN_FUNCTION_TYPE comres = C_BMG160_Zero_U8X ;
	unsigned char data1 = C_BMG160_Zero_U8X;
	unsigned char data2 = C_BMG160_Zero_U8X;
	unsigned char data3 = C_BMG160_Zero_U8X;
	if (p_bmg160 == C_BMG160_Zero_U8X) {
		comres = E_BMG160_NULL_PTR;
	} else {
		comres = p_bmg160->BMG160_BUS_READ_FUNC(p_bmg160->dev_addr, \
		BMG160_MODE_LPM1_ADDR, &data1, C_BMG160_One_U8X);
		comres = p_bmg160->BMG160_BUS_READ_FUNC(p_bmg160->dev_addr, \
		BMG160_MODE_LPM2_ADDR, &data2, C_BMG160_One_U8X);
		data1  = (data1 & 0xA0) >> 5;
		data3  = (data2 & 0x40) >> 6;
		data2  = (data2 & 0x80) >> 7;
		if (data3 == 0x01) {
			*Mode  = BMG160_MODE_ADVANCEDPOWERSAVING;
		} else {
			if ((data1 == 0x00) && (data2 == 0x00)) {
				*Mode  = BMG160_MODE_NORMAL;
				} else {
				if ((data1 == 0x01) || (data1 == 0x05)) {
					*Mode  = BMG160_MODE_DEEPSUSPEND;
					} else {
					if ((data1 == 0x04) &&\
					(data2 == 0x00)) {
						*Mode  = BMG160_MODE_SUSPEND;
						} else {
						if ((data1 == 0x04) &&\
						(data2 == 0x01))
							*Mode  =\
							BMG160_MODE_FASTPOWERUP;
						}
					}
				}
			}
		}
	return comres;
}
BMG160_RETURN_FUNCTION_TYPE bmg160_set_mode(unsigned char Mode)
{
	BMG160_RETURN_FUNCTION_TYPE comres = C_BMG160_Zero_U8X ;
	unsigned char data1;
	unsigned char data2;
	unsigned char data3;
	unsigned char v_autosleepduration;
	unsigned char v_bw_u8r;
	if (p_bmg160 == C_BMG160_Zero_U8X) {
		comres = E_BMG160_NULL_PTR;
	} else {
		if (Mode < C_BMG160_Five_U8X) {
			comres = p_bmg160->BMG160_BUS_READ_FUNC\
				(p_bmg160->dev_addr,\
			BMG160_MODE_LPM1_ADDR, &data1, C_BMG160_One_U8X);
			comres = p_bmg160->BMG160_BUS_READ_FUNC\
				(p_bmg160->dev_addr,\
			BMG160_MODE_LPM2_ADDR, &data2, C_BMG160_One_U8X);
			switch (Mode) {
			case BMG160_MODE_NORMAL:
				data1  = BMG160_SET_BITSLICE(data1,\
				BMG160_MODE_LPM1, C_BMG160_Zero_U8X);
				data2  = BMG160_SET_BITSLICE(data2,\
				BMG160_MODE_LPM2_ADDR_FAST_POWERUP,\
				C_BMG160_Zero_U8X);
				data3  = BMG160_SET_BITSLICE(data2,\
				BMG160_MODE_LPM2_ADDR_ADV_POWERSAVING,\
				C_BMG160_Zero_U8X);
				comres += p_bmg160->BMG160_BUS_WRITE_FUNC\
				(p_bmg160->dev_addr,\
			BMG160_MODE_LPM1_ADDR, &data1, C_BMG160_One_U8X);
			p_bmg160->delay_msec(1);
			comres += p_bmg160->BMG160_BUS_WRITE_FUNC\
				(p_bmg160->dev_addr,\
			BMG160_MODE_LPM2_ADDR, &data3, C_BMG160_One_U8X);
				break;
			case BMG160_MODE_DEEPSUSPEND:
				data1  = BMG160_SET_BITSLICE(data1,\
				BMG160_MODE_LPM1, C_BMG160_One_U8X);
				data2  = BMG160_SET_BITSLICE(data2,\
				BMG160_MODE_LPM2_ADDR_FAST_POWERUP,\
				C_BMG160_Zero_U8X);
				data3  = BMG160_SET_BITSLICE(data2,\
				BMG160_MODE_LPM2_ADDR_ADV_POWERSAVING,\
				C_BMG160_Zero_U8X);
				comres += p_bmg160->BMG160_BUS_WRITE_FUNC\
				(p_bmg160->dev_addr,\
			BMG160_MODE_LPM1_ADDR, &data1, C_BMG160_One_U8X);
			p_bmg160->delay_msec(1);
			comres += p_bmg160->BMG160_BUS_WRITE_FUNC\
				(p_bmg160->dev_addr,\
			BMG160_MODE_LPM2_ADDR, &data3, C_BMG160_One_U8X);
				break;
			case BMG160_MODE_SUSPEND:
				data1  = BMG160_SET_BITSLICE(data1,\
				BMG160_MODE_LPM1, C_BMG160_Four_U8X);
				data2  = BMG160_SET_BITSLICE(data2,\
				BMG160_MODE_LPM2_ADDR_FAST_POWERUP,\
				C_BMG160_Zero_U8X);
				data3  = BMG160_SET_BITSLICE(data2,\
				BMG160_MODE_LPM2_ADDR_ADV_POWERSAVING,\
				C_BMG160_Zero_U8X);
				comres += p_bmg160->BMG160_BUS_WRITE_FUNC\
				(p_bmg160->dev_addr,\
			BMG160_MODE_LPM1_ADDR, &data1, C_BMG160_One_U8X);
			p_bmg160->delay_msec(1);
			comres += p_bmg160->BMG160_BUS_WRITE_FUNC\
				(p_bmg160->dev_addr,\
			BMG160_MODE_LPM2_ADDR, &data3, C_BMG160_One_U8X);
				break;
			case BMG160_MODE_FASTPOWERUP:
				data1  = BMG160_SET_BITSLICE(data1,\
				BMG160_MODE_LPM1, C_BMG160_Four_U8X);
				data2  = BMG160_SET_BITSLICE(data2,\
				BMG160_MODE_LPM2_ADDR_FAST_POWERUP, \
				C_BMG160_One_U8X);
				data3  = BMG160_SET_BITSLICE(data2,\
				BMG160_MODE_LPM2_ADDR_ADV_POWERSAVING,\
				C_BMG160_Zero_U8X);
				comres += p_bmg160->BMG160_BUS_WRITE_FUNC\
				(p_bmg160->dev_addr,\
			BMG160_MODE_LPM1_ADDR, &data1, C_BMG160_One_U8X);
			p_bmg160->delay_msec(1);
			comres += p_bmg160->BMG160_BUS_WRITE_FUNC\
				(p_bmg160->dev_addr,\
			BMG160_MODE_LPM2_ADDR, &data3, C_BMG160_One_U8X);
				break;
			case BMG160_MODE_ADVANCEDPOWERSAVING:
				bmg160_get_bw(&v_bw_u8r);
				bmg160_get_autosleepdur(&v_autosleepduration);
				bmg160_set_autosleepdur(v_autosleepduration, \
				v_bw_u8r);
				comres += p_bmg160->BMG160_BUS_READ_FUNC\
					(p_bmg160->dev_addr,\
				BMG160_MODE_LPM2_ADDR, &data2,\
				C_BMG160_One_U8X);
				
				data1  = BMG160_SET_BITSLICE(data1,\
				BMG160_MODE_LPM1, C_BMG160_Zero_U8X);
				data2  = BMG160_SET_BITSLICE(data2,\
				BMG160_MODE_LPM2_ADDR_FAST_POWERUP, \
				C_BMG160_Zero_U8X);
				data3  = BMG160_SET_BITSLICE(data2,\
				BMG160_MODE_LPM2_ADDR_ADV_POWERSAVING,\
				C_BMG160_One_U8X);
				comres += p_bmg160->BMG160_BUS_WRITE_FUNC\
				(p_bmg160->dev_addr,\
			BMG160_MODE_LPM1_ADDR, &data1, C_BMG160_One_U8X);
			p_bmg160->delay_msec(1);
			comres += p_bmg160->BMG160_BUS_WRITE_FUNC\
				(p_bmg160->dev_addr,\
			BMG160_MODE_LPM2_ADDR, &data3, C_BMG160_One_U8X);
				break;
				}
		} else {
		comres = E_BMG160_OUT_OF_RANGE ;
		}
	}
	return comres;
}
BMG160_RETURN_FUNCTION_TYPE bmg160_selftest(unsigned char *result)
	{
	BMG160_RETURN_FUNCTION_TYPE comres = C_BMG160_Zero_U8X ;
	unsigned char data1 = C_BMG160_Zero_U8X;
	unsigned char data2 = C_BMG160_Zero_U8X;

	comres = p_bmg160->BMG160_BUS_READ_FUNC(p_bmg160->dev_addr,\
	BMG160_SELF_TEST_ADDR, &data1, C_BMG160_One_U8X);
	data2  = BMG160_GET_BITSLICE(data1, BMG160_SELF_TEST_ADDR_RATEOK);
	data1  = BMG160_SET_BITSLICE(data1, BMG160_SELF_TEST_ADDR_TRIGBIST,
	C_BMG160_One_U8X);
	comres += p_bmg160->BMG160_BUS_WRITE_FUNC(p_bmg160->dev_addr,\
	BMG160_SELF_TEST_ADDR_TRIGBIST__REG, &data1, C_BMG160_One_U8X);

	
	p_bmg160->delay_msec(10);

	
	comres = p_bmg160->BMG160_BUS_READ_FUNC(p_bmg160->dev_addr,\
	BMG160_SELF_TEST_ADDR_BISTFAIL__REG, &data1, C_BMG160_One_U8X);
	data1  = BMG160_GET_BITSLICE(data1, BMG160_SELF_TEST_ADDR_BISTFAIL);
	if ((data1 == 0x00) && (data2 == 0x01))
		*result = C_BMG160_SUCCESS;
	else
		*result = C_BMG160_FAILURE;
	return comres;
}
BMG160_RETURN_FUNCTION_TYPE bmg160_get_autosleepdur(unsigned char *duration)
{
	BMG160_RETURN_FUNCTION_TYPE comres;
	unsigned char v_data_u8r;
	if (p_bmg160 == BMG160_NULL) {
		comres = E_BMG160_NULL_PTR;
	} else {
		comres = p_bmg160->BMG160_BUS_READ_FUNC(p_bmg160->dev_addr,\
		 BMG160_MODE_LPM2_ADDR_AUTOSLEEPDUR__REG, &v_data_u8r, 1);
		*duration = BMG160_GET_BITSLICE(v_data_u8r,\
		BMG160_MODE_LPM2_ADDR_AUTOSLEEPDUR);
	}
	return comres;
}
/**\brief This API is used to set duration
 *
 *
 *
 *
 *  \param unsigned char duration:
 *          Value to be written passed as a parameter
 *
 *
 *
 *  \return communication results
 *
 *
 *****************************************************************************/
BMG160_RETURN_FUNCTION_TYPE bmg160_set_autosleepdur(unsigned char duration, \
unsigned char bandwith)
{
	BMG160_RETURN_FUNCTION_TYPE comres;
	unsigned char v_data_u8r;
	unsigned char v_autosleepduration_u8r = 0;
	if (p_bmg160 == BMG160_NULL) {
		comres = E_BMG160_NULL_PTR;
	} else {
		comres = p_bmg160->BMG160_BUS_READ_FUNC\
			(p_bmg160->dev_addr,\
			BMG160_MODE_LPM2_ADDR_AUTOSLEEPDUR__REG,\
			&v_data_u8r, 1);
			if (duration < C_BMG160_Eight_U8X) {
				switch (bandwith) {
				case C_BMG160_No_Filter_U8X:
					if (duration >
					C_BMG160_4ms_AutoSleepDur_U8X)
						v_autosleepduration_u8r =\
						duration;
					else
						v_autosleepduration_u8r =\
						C_BMG160_4ms_AutoSleepDur_U8X;
					break;
				case C_BMG160_BW_230Hz_U8X:
					if (duration >
					C_BMG160_4ms_AutoSleepDur_U8X)
						v_autosleepduration_u8r =\
						duration;
					else
						v_autosleepduration_u8r =\
						C_BMG160_4ms_AutoSleepDur_U8X;
					break;
				case C_BMG160_BW_116Hz_U8X:
					if (duration >
					C_BMG160_4ms_AutoSleepDur_U8X)
						v_autosleepduration_u8r =\
						duration;
					else
						v_autosleepduration_u8r =\
						C_BMG160_4ms_AutoSleepDur_U8X;
					break;
				case C_BMG160_BW_47Hz_U8X:
					if (duration >
					C_BMG160_5ms_AutoSleepDur_U8X)
						v_autosleepduration_u8r =\
						duration;
					else
						v_autosleepduration_u8r =\
						C_BMG160_5ms_AutoSleepDur_U8X;
					break;
				case C_BMG160_BW_23Hz_U8X:
					if (duration >
					C_BMG160_10ms_AutoSleepDur_U8X)
						v_autosleepduration_u8r =\
						duration;
					else
						v_autosleepduration_u8r =\
						C_BMG160_10ms_AutoSleepDur_U8X;
					break;
				case C_BMG160_BW_12Hz_U8X:
					if (duration >
					C_BMG160_20ms_AutoSleepDur_U8X)
						v_autosleepduration_u8r =\
						duration;
					else
					v_autosleepduration_u8r =\
					C_BMG160_20ms_AutoSleepDur_U8X;
					break;
				case C_BMG160_BW_64Hz_U8X:
					if (duration >
					C_BMG160_10ms_AutoSleepDur_U8X)
						v_autosleepduration_u8r =\
						duration;
					else
						v_autosleepduration_u8r =\
						C_BMG160_10ms_AutoSleepDur_U8X;
					break;
				case C_BMG160_BW_32Hz_U8X:
					if (duration >
					C_BMG160_20ms_AutoSleepDur_U8X)
						v_autosleepduration_u8r =\
						duration;
					else
						v_autosleepduration_u8r =\
						C_BMG160_20ms_AutoSleepDur_U8X;
					break;
				}
			v_data_u8r = BMG160_SET_BITSLICE(v_data_u8r,\
			BMG160_MODE_LPM2_ADDR_AUTOSLEEPDUR,\
			v_autosleepduration_u8r);
			comres = p_bmg160->BMG160_BUS_WRITE_FUNC\
				(p_bmg160->dev_addr,\
			BMG160_MODE_LPM2_ADDR_AUTOSLEEPDUR__REG,\
			&v_data_u8r, 1);
		} else {
			comres = E_BMG160_OUT_OF_RANGE;
		}
	}
	return comres;
}
BMG160_RETURN_FUNCTION_TYPE bmg160_get_sleepdur(unsigned char *duration)
{
	BMG160_RETURN_FUNCTION_TYPE comres;
	unsigned char v_data_u8r;
	if (p_bmg160 == BMG160_NULL) {
		comres = E_BMG160_NULL_PTR;
	} else {
		comres = p_bmg160->BMG160_BUS_READ_FUNC(p_bmg160->dev_addr,\
		 BMG160_MODELPM1_ADDR_SLEEPDUR__REG, &v_data_u8r, 1);
		*duration = BMG160_GET_BITSLICE(v_data_u8r,\
		BMG160_MODELPM1_ADDR_SLEEPDUR);
	}
	return comres;
}
/**\brief This API is used to set duration
 *
 *
 *
 *
 *  \param unsigned char duration:
 *          Value to be written passed as a parameter
 *
 *
 *
 *  \return communication results
 *
 *
 *****************************************************************************/
BMG160_RETURN_FUNCTION_TYPE bmg160_set_sleepdur(unsigned char duration)
{
	BMG160_RETURN_FUNCTION_TYPE comres;
	unsigned char v_data_u8r;
	if (p_bmg160 == BMG160_NULL) {
		comres = E_BMG160_NULL_PTR;
	} else {
		if (duration < C_BMG160_Eight_U8X) {
			comres = p_bmg160->BMG160_BUS_READ_FUNC\
				(p_bmg160->dev_addr,\
			BMG160_MODELPM1_ADDR_SLEEPDUR__REG,\
			&v_data_u8r, 1);
			v_data_u8r = BMG160_SET_BITSLICE(v_data_u8r,\
			BMG160_MODELPM1_ADDR_SLEEPDUR, duration);
			comres = p_bmg160->BMG160_BUS_WRITE_FUNC\
				(p_bmg160->dev_addr,\
			BMG160_MODELPM1_ADDR_SLEEPDUR__REG,\
			&v_data_u8r, 1);
		} else {
			comres = E_BMG160_OUT_OF_RANGE;
		}
	}
	return comres;
}


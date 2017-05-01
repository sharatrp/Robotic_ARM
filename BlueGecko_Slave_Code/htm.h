/***********************************************************************************************//**
 * \file   htm.h
 * \brief  Health Thermometer Service
 ***************************************************************************************************
 * <b> (C) Copyright 2015 Silicon Labs, http://www.silabs.com</b>
 ***************************************************************************************************
 * This file is licensed under the Silabs License Agreement. See the file
 * "Silabs_License_Agreement.txt" for details. Before using this software for
 * any purpose, you must agree to the terms of that agreement.
 **************************************************************************************************/

#ifndef HTM_H
#define HTM_H

#ifdef __cplusplus
extern "C" {
#endif

/***********************************************************************************************//**
 * \defgroup htm Health Thermometer
 * \brief Health Thermometer Service API
 **************************************************************************************************/

/***********************************************************************************************//**
 * @addtogroup Services
 * @{
 **************************************************************************************************/

/***********************************************************************************************//**
 * @addtogroup htm
 * @{
 **************************************************************************************************/


/***************************************************************************************************
  Public Macros and Definitions
***************************************************************************************************/


/***************************************************************************************************
  Structures and Enumerations
***************************************************************************************************/

/* This macro will be used to send the flex sensor data instead of the
 * temperature value in the temperature field of HTM service */
#define SEND_FLEX_SENSOR_DATA_INSTEAD_OF_TEMP_DATA

/** Humidity measurement structure. */
PACKSTRUCT(struct htmHumidityMeas_t {
	uint16_t humidity;    /**< Humidity */
});

struct htmHumidityMeas_t htmHumidityMeas;

/***************************************************************************************************
  Function Declarations
***************************************************************************************************/

uint8_t htmProcMsg(uint8_t *buf);

/***********************************************************************************************//**
 *  \brief  Initialise Health Thermometer Service.
 *  \details  Initialise the connection ID, the configuration flags of the temperature measurement
 *  and stop temperature measurement timer.
 **************************************************************************************************/
void htmInit(void);

/***********************************************************************************************//**
 *  \brief  Temperature CCCD has changed event handler function.
 *  \param[in]  connection  Connection ID.
 *  \param[in]  clientConfig  New value of CCCD.
**************************************************************************************************/
void htmTemperatureCharStatusChange(uint8_t connection, uint16_t clientConfig);

/***********************************************************************************************//**
 *  \brief  Make one temperature measurement.
 **************************************************************************************************/
void htmTemperatureMeasure(void);

/***********************************************************************************************//**
 *  \brief  Make one humididty measurement.
 **************************************************************************************************/
#if 0
void htmHumidityMeasure(void);
#endif


/** @} (end addtogroup htm) */
/** @} (end addtogroup Services) */

#ifdef __cplusplus
};
#endif

#endif /* HTM_H */

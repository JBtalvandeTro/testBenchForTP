/*!
 * \file     TYPedef.h
 * \brief    Type definition file
 *
 *           TRONICO
 *           26, rue du bocage
 *           85660 St Philbert De Bouaine
 **/

#ifndef FILE_TYPEDEF_H
#define FILE_TYPEDEF_H

/* ---- Includes ---- */
#include "StandardTypes.h"
#include "stdbool.h"

/* ---- Defines ---- */
typedef	signed		char	int8_t;
typedef	signed		short	int16_t;

typedef	unsigned	char	uint8_t;
typedef	unsigned	short	uint16_t;

typedef				float	float32_t;
typedef				double	float64_t;
typedef	long		double	float128_t;

typedef 			boolean	bool_t;


#define ENTER_CRITICAL_SECTION  ASM_KEYWORD(" cpsid i")
#define EXIT_CRITICAL_SECTION   ASM_KEYWORD(" cpsie i")

#endif /* FILE_TYPEDEF_H */

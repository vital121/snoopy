/*
 * SNOOPY COMMAND LOGGER
 *
 * File: snoopy/output/devttyoutput.c
 *
 * Copyright (c) 2014-2015 Bostjan Skufca (bostjan _A_T_ a2o.si)
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2, or (at your option)
 * any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software Foundation,
 * Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 */



/*
 * Includes order: from local to global
 */
#include "devttyoutput.h"

#include "output/fileoutput.h"



/*
 * SNOOPY OUTPUT: devttyoutput
 *
 * Description:
 *     Sends given message directly to /dev/tty
 *
 * Params:
 *     message:    message to send
 *     arg:        output argument(s)
 *
 * Return:
 *     int:        See snoopy.h (SNOOPY_OUTPUT_*) for details.
 */
int snoopy_output_devttyoutput (char const * const logMessage, __attribute__((unused)) char const * const arg)
{
    return snoopy_output_fileoutput(logMessage, "/dev/tty");
}

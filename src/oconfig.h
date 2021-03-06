/**
 * collection4 - oconfig.h
 * Copyright (C) 2006-2010  Florian octo Forster
 * 
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 * 
 * You should have received a copy of the GNU Lesser General Public
 * License along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor,
 * Boston, MA  02110-1301  USA
 *
 * Authors:
 *   Florian octo Forster <ff at octo.it>
 **/

#ifndef OCONFIG_H
#define OCONFIG_H 1

#include <stdio.h>

/*
 * Types
 */
#define OCONFIG_TYPE_STRING  0
#define OCONFIG_TYPE_NUMBER  1
#define OCONFIG_TYPE_BOOLEAN 2

struct oconfig_value_s
{
  union
  {
    char  *string;
    double number;
    int    boolean;
  } value;
  int type;
};
typedef struct oconfig_value_s oconfig_value_t;

struct oconfig_item_s;
typedef struct oconfig_item_s oconfig_item_t;
struct oconfig_item_s
{
  char            *key;
  oconfig_value_t *values;
  int              values_num;

  oconfig_item_t  *parent;
  oconfig_item_t  *children;
  int              children_num;
};

/*
 * Functions
 */
oconfig_item_t *oconfig_parse_fh (FILE *fh);
oconfig_item_t *oconfig_parse_file (const char *file);

oconfig_item_t *oconfig_clone (const oconfig_item_t *ci);

void oconfig_free (oconfig_item_t *ci);

/*
 * vim: shiftwidth=2:tabstop=8:softtabstop=2
 */
#endif /* OCONFIG_H */

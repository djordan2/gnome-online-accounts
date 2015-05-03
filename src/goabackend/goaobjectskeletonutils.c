/* -*- mode: C; c-file-style: "gnu"; indent-tabs-mode: nil; -*- */
/*
 * Copyright (C) 2012, 2013, 2015 Red Hat, Inc.
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General
 * Public License along with this library; if not, see <http://www.gnu.org/licenses/>.
 */

#include "config.h"

#include <glib/gi18n-lib.h>

#include "goaobjectskeletonutils.h"

void
goa_object_skeleton_attach_calendar (GoaObjectSkeleton *object,
                                     const gchar       *uri,
                                     gboolean           calendar_enabled,
                                     gboolean           accept_ssl_errors)
{
  GoaCalendar *calendar;

  calendar = goa_object_get_calendar (GOA_OBJECT (object));
  if (calendar_enabled)
    {
      if (calendar == NULL)
        {
          calendar = goa_calendar_skeleton_new ();
          g_object_set (G_OBJECT (calendar),
                        "accept-ssl-errors", accept_ssl_errors,
                        "uri", uri,
                        NULL);
          goa_object_skeleton_set_calendar (object, calendar);
        }
    }
  else
    {
      if (calendar != NULL)
        goa_object_skeleton_set_calendar (object, NULL);
    }
  g_clear_object (&calendar);
}

void
goa_object_skeleton_attach_files (GoaObjectSkeleton *object,
                                  const gchar       *uri,
                                  gboolean           files_enabled,
                                  gboolean           accept_ssl_errors)
{
  GoaFiles *files;

  files = goa_object_get_files (GOA_OBJECT (object));
  if (files_enabled)
    {
      if (files == NULL)
        {
          files = goa_files_skeleton_new ();
          g_object_set (G_OBJECT (files),
                        "accept-ssl-errors", accept_ssl_errors,
                        "uri", uri,
                        NULL);
          goa_object_skeleton_set_files (object, files);
        }
    }
  else
    {
      if (files != NULL)
        goa_object_skeleton_set_files (object, NULL);
    }
  g_clear_object (&files);
}
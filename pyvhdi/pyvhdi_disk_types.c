/*
 * Python object definition of the libvhdi disk types
 *
 * Copyright (C) 2012-2014, Joachim Metz <joachim.metz@gmail.com>
 *
 * Refer to AUTHORS for acknowledgements.
 *
 * This software is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This software is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this software.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <common.h>
#include <types.h>

#if defined( HAVE_STDLIB_H ) || defined( HAVE_WINAPI )
#include <stdlib.h>
#endif

#include "pyvhdi_disk_types.h"
#include "pyvhdi_libvhdi.h"
#include "pyvhdi_python.h"
#include "pyvhdi_unused.h"

PyTypeObject pyvhdi_disk_types_type_object = {
	PyObject_HEAD_INIT( NULL )

	/* ob_size */
	0,
	/* tp_name */
	"pyvhdi.disk_types",
	/* tp_basicsize */
	sizeof( pyvhdi_disk_types_t ),
	/* tp_itemsize */
	0,
	/* tp_dealloc */
	(destructor) pyvhdi_disk_types_free,
	/* tp_print */
	0,
	/* tp_getattr */
	0,
	/* tp_setattr */
	0,
	/* tp_compare */
	0,
	/* tp_repr */
	0,
	/* tp_as_number */
	0,
	/* tp_as_sequence */
	0,
	/* tp_as_mapping */
	0,
	/* tp_hash */
	0,
	/* tp_call */
	0,
	/* tp_str */
	0,
	/* tp_getattro */
	0,
	/* tp_setattro */
	0,
	/* tp_as_buffer */
	0,
        /* tp_flags */
	Py_TPFLAGS_DEFAULT,
	/* tp_doc */
	"pyvhdi disk types object (wraps LIBVHDI_DISK_TYPES)",
	/* tp_traverse */
	0,
	/* tp_clear */
	0,
	/* tp_richcompare */
	0,
	/* tp_weaklistoffset */
	0,
	/* tp_iter */
	0,
	/* tp_iternext */
	0,
	/* tp_methods */
	0,
	/* tp_members */
	0,
	/* tp_getset */
	0,
	/* tp_base */
	0,
	/* tp_dict */
	0,
	/* tp_descr_get */
	0,
	/* tp_descr_set */
	0,
	/* tp_dictoffset */
	0,
	/* tp_init */
	(initproc) pyvhdi_disk_types_init,
	/* tp_alloc */
	0,
	/* tp_new */
	0,
	/* tp_free */
	0,
	/* tp_is_gc */
	0,
	/* tp_bases */
	NULL,
	/* tp_mro */
	NULL,
	/* tp_cache */
	NULL,
	/* tp_subclasses */
	NULL,
	/* tp_weaklist */
	NULL,
	/* tp_del */
	0
};

/* Initializes the type object
 * Returns 1 if successful or -1 on error
 */
int pyvhdi_disk_types_init_type(
     PyTypeObject *type_object )
{
	if( type_object == NULL )
	{
		return( -1 );
	}
	type_object->tp_dict = PyDict_New();

	if( type_object->tp_dict == NULL )
	{
		return( -1 );
	}
	if( PyDict_SetItemString(
             type_object->tp_dict,
             "FIXED",
             PyInt_FromLong(
              LIBVHDI_DISK_TYPE_FIXED ) ) != 0 )
	{
		goto on_error;
	}
	if( PyDict_SetItemString(
             type_object->tp_dict,
             "DYNAMIC",
             PyInt_FromLong(
              LIBVHDI_DISK_TYPE_DYNAMIC ) ) != 0 )
	{
		goto on_error;
	}
	if( PyDict_SetItemString(
             type_object->tp_dict,
             "DIFFERENTIAL",
             PyInt_FromLong(
              LIBVHDI_DISK_TYPE_DIFFERENTIAL ) ) != 0 )
	{
		goto on_error;
	}
	return( 1 );

on_error:
	if( type_object->tp_dict != NULL )
	{
		Py_DecRef(
		 type_object->tp_dict );

		type_object->tp_dict = NULL;
	}
	return( -1 );
}

/* Creates a new disk types object
 * Returns a Python object if successful or NULL on error
 */
PyObject *pyvhdi_disk_types_new(
           void )
{
	pyvhdi_disk_types_t *pyvhdi_disk_types = NULL;
	static char *function                  = "pyvhdi_disk_types_new";

	pyvhdi_disk_types = PyObject_New(
	                     struct pyvhdi_disk_types,
	                     &pyvhdi_disk_types_type_object );

	if( pyvhdi_disk_types == NULL )
	{
		PyErr_Format(
		 PyExc_MemoryError,
		 "%s: unable to initialize disk types.",
		 function );

		goto on_error;
	}
	if( pyvhdi_disk_types_init(
	     pyvhdi_disk_types ) != 0 )
	{
		PyErr_Format(
		 PyExc_MemoryError,
		 "%s: unable to initialize disk types.",
		 function );

		goto on_error;
	}
	return( (PyObject *) pyvhdi_disk_types );

on_error:
	if( pyvhdi_disk_types != NULL )
	{
		Py_DecRef(
		 (PyObject *) pyvhdi_disk_types );
	}
	return( NULL );
}

/* Intializes a disk types object
 * Returns 0 if successful or -1 on error
 */
int pyvhdi_disk_types_init(
     pyvhdi_disk_types_t *pyvhdi_disk_types )
{
	static char *function = "pyvhdi_disk_types_init";

	if( pyvhdi_disk_types == NULL )
	{
		PyErr_Format(
		 PyExc_TypeError,
		 "%s: invalid disk types.",
		 function );

		return( -1 );
	}
	return( 0 );
}

/* Frees a disk types object
 */
void pyvhdi_disk_types_free(
      pyvhdi_disk_types_t *pyvhdi_disk_types )
{
	static char *function = "pyvhdi_disk_types_free";

	if( pyvhdi_disk_types == NULL )
	{
		PyErr_Format(
		 PyExc_TypeError,
		 "%s: invalid disk types.",
		 function );

		return;
	}
	if( pyvhdi_disk_types->ob_type == NULL )
	{
		PyErr_Format(
		 PyExc_TypeError,
		 "%s: invalid disk types - missing ob_type.",
		 function );

		return;
	}
	if( pyvhdi_disk_types->ob_type->tp_free == NULL )
	{
		PyErr_Format(
		 PyExc_TypeError,
		 "%s: invalid disk types - invalid ob_type - missing tp_free.",
		 function );

		return;
	}
	pyvhdi_disk_types->ob_type->tp_free(
	 (PyObject*) pyvhdi_disk_types );
}

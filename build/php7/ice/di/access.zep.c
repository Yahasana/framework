
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/memory.h"
#include "kernel/object.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"


/**
 * This class allows to access services in the services container by just only accessing a public property with the same
 * name of a registered service.
 *
 * @package     Ice/Di
 * @category    Helper
 * @author      Ice Team
 * @copyright   (c) 2014-2016 Ice Team
 * @license     http://iceframework.org/license
 */
ZEPHIR_INIT_CLASS(Ice_Di_Access) {

	ZEPHIR_REGISTER_CLASS(Ice\\Di, Access, ice, di_access, ice_di_access_method_entry, 0);

	zend_declare_property_null(ice_di_access_ce, SL("di"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

/**
 * Magic get to easy retrieve service from the di.
 */
PHP_METHOD(Ice_Di_Access, __get) {

	zend_bool _1, _3;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_6 = NULL;
	zval *property_param = NULL, di, service, _0, _2, _4, _7, _5$$3;
	zval property;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&property);
	ZVAL_UNDEF(&di);
	ZVAL_UNDEF(&service);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_5$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &property_param);

	zephir_get_strval(&property, property_param);


	ZEPHIR_OBS_VAR(&_0);
	zephir_read_property(&_0, this_ptr, SL("di"), PH_NOISY_CC);
	_1 = Z_TYPE_P(&_0) != IS_OBJECT;
	if (!(_1)) {
		ZEPHIR_OBS_VAR(&_2);
		zephir_read_property(&_2, this_ptr, SL("di"), PH_NOISY_CC);
		_3 = Z_TYPE_P(&_2) == IS_OBJECT;
		if (_3) {
			ZEPHIR_OBS_VAR(&_4);
			zephir_read_property(&_4, this_ptr, SL("di"), PH_NOISY_CC);
			_3 = !(zephir_instance_of_ev(&_4, ice_di_ce TSRMLS_CC));
		}
		_1 = _3;
	}
	if (_1) {
		ZEPHIR_CALL_CE_STATIC(&_5$$3, ice_di_ce, "fetch", &_6, 0);
		zephir_check_call_status();
		zephir_update_property_zval(this_ptr, SL("di"), &_5$$3);
	}
	zephir_read_property(&_7, this_ptr, SL("di"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&di, &_7);
	if (ZEPHIR_IS_STRING(&property, "di")) {
		zephir_update_property_zval(this_ptr, SL("di"), &di);
		RETURN_CCTOR(di);
	}
	ZEPHIR_CALL_METHOD(&service, &di, "get", NULL, 0, &property);
	zephir_check_call_status();
	zephir_update_property_zval_zval(this_ptr, &property, &service TSRMLS_CC);
	RETURN_CCTOR(service);

}

PHP_METHOD(Ice_Di_Access, __set) {

	zend_bool _1, _3;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_6 = NULL;
	zval *property_param = NULL, *value, value_sub, _0, _2, _4, _7, _5$$3;
	zval property;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&property);
	ZVAL_UNDEF(&value_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_5$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &property_param, &value);

	zephir_get_strval(&property, property_param);


	ZEPHIR_OBS_VAR(&_0);
	zephir_read_property(&_0, this_ptr, SL("di"), PH_NOISY_CC);
	_1 = Z_TYPE_P(&_0) != IS_OBJECT;
	if (!(_1)) {
		ZEPHIR_OBS_VAR(&_2);
		zephir_read_property(&_2, this_ptr, SL("di"), PH_NOISY_CC);
		_3 = Z_TYPE_P(&_2) == IS_OBJECT;
		if (_3) {
			ZEPHIR_OBS_VAR(&_4);
			zephir_read_property(&_4, this_ptr, SL("di"), PH_NOISY_CC);
			_3 = !(zephir_instance_of_ev(&_4, ice_di_ce TSRMLS_CC));
		}
		_1 = _3;
	}
	if (_1) {
		ZEPHIR_CALL_CE_STATIC(&_5$$3, ice_di_ce, "fetch", &_6, 0);
		zephir_check_call_status();
		zephir_update_property_zval(this_ptr, SL("di"), &_5$$3);
	}
	zephir_read_property(&_7, this_ptr, SL("di"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_7, "set", NULL, 0, &property, value);
	zephir_check_call_status();
	RETURN_MM();

}


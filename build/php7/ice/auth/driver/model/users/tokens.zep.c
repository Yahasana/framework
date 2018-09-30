
#ifdef HAVE_CONFIG_H
#include "../../../../../ext_config.h"
#endif

#include <php.h>
#include "../../../../../php_ext.h"
#include "../../../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/object.h"
#include "kernel/array.h"
#include "kernel/math.h"
#include "kernel/operators.h"
#include "kernel/time.h"
#include "kernel/iterator.h"


/**
 * Model user's Tokens.
 *
 * @package     Ice/Auth
 * @category    Model
 * @author      Ice Team
 * @copyright   (c) 2014-2018 Ice Team
 * @license     http://iceframework.org/license
 */
ZEPHIR_INIT_CLASS(Ice_Auth_Driver_Model_Users_Tokens) {

	ZEPHIR_REGISTER_CLASS_EX(Ice\\Auth\\Driver\\Model\\Users, Tokens, ice, auth_driver_model_users_tokens, ice_mvc_model_ce, ice_auth_driver_model_users_tokens_method_entry, 0);

	zend_declare_property_string(ice_auth_driver_model_users_tokens_ce, SL("from"), "user_tokens", ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * User class name.
	 */
	zend_declare_property_string(ice_auth_driver_model_users_tokens_ce, SL("userClass"), "Ice\\Auth\\Driver\\Model\\Users", ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

/**
 * Initialize token's relations, remove expired tokens.
 *
 * @return void
 */
PHP_METHOD(Ice_Auth_Driver_Model_Users_Tokens, initialize) {

	zend_bool _9, _11;
	zval _5;
	zval __$true, auth, _0, _1, _2, _3, _4, _6, _7, _8, _10, _12;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&auth);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_12);
	ZVAL_UNDEF(&_5);

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getdi", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "auth");
	ZEPHIR_CALL_METHOD(&auth, &_0, "get", NULL, 0, &_1);
	zephir_check_call_status();
	zephir_read_property(&_3, this_ptr, SL("userClass"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "users");
	ZEPHIR_CALL_METHOD(&_2, &auth, "getoption", NULL, 0, &_1, &_3);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_4, this_ptr, "getidkey", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_5);
	zephir_create_array(&_5, 2, 0 TSRMLS_CC);
	add_assoc_stringl_ex(&_5, SL("alias"), SL("User"));
	zephir_array_update_string(&_5, SL("foreignKey"), &__$true, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "user_id");
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "belongsto", NULL, 0, &_1, &_2, &_4, &_5);
	zephir_check_call_status();
	ZVAL_LONG(&_6, 1);
	ZVAL_LONG(&_7, 100);
	if (zephir_mt_rand(zephir_get_intval(&_6), zephir_get_intval(&_7) TSRMLS_CC) == 1) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "deleteexpired", NULL, 0);
		zephir_check_call_status();
	}
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "expires");
	ZEPHIR_CALL_METHOD(&_8, this_ptr, "has", NULL, 0, &_1);
	zephir_check_call_status();
	_9 = zephir_is_true(&_8);
	if (_9) {
		ZEPHIR_INIT_NVAR(&_1);
		ZVAL_STRING(&_1, "expires");
		ZEPHIR_CALL_METHOD(&_10, this_ptr, "get", NULL, 0, &_1);
		zephir_check_call_status();
		_9 = zephir_is_true(&_10);
	}
	_11 = _9;
	if (_11) {
		ZEPHIR_INIT_NVAR(&_1);
		ZVAL_STRING(&_1, "expires");
		ZEPHIR_CALL_METHOD(&_12, this_ptr, "get", NULL, 0, &_1);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&_1);
		zephir_time(&_1);
		_11 = ZEPHIR_LT(&_12, &_1);
	}
	if (_11) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "remove", NULL, 0);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Generate a new unique token and create the token.
 *
 * @param array fields Fields to save or valid fields
 * @param object extra Extra validation
 * @return mixed
 */
PHP_METHOD(Ice_Auth_Driver_Model_Users_Tokens, create) {

	zephir_fcall_cache_entry *_1 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *fields = NULL, fields_sub, *extra = NULL, extra_sub, __$null, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&fields_sub);
	ZVAL_UNDEF(&extra_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &fields, &extra);

	if (!fields) {
		fields = &fields_sub;
		ZEPHIR_INIT_VAR(fields);
		array_init(fields);
	}
	if (!extra) {
		extra = &extra_sub;
		extra = &__$null;
	}


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "generate", NULL, 0);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, SL("token"), &_0);
	ZEPHIR_RETURN_CALL_PARENT(ice_auth_driver_model_users_tokens_ce, getThis(), "create", &_1, 0, fields);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Deletes all expired tokens.
 *
 * @return void
 */
PHP_METHOD(Ice_Auth_Driver_Model_Users_Tokens, deleteExpired) {

	zend_object_iterator *_3;
	zval _0, _1;
	zval token, expired, _2;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&token);
	ZVAL_UNDEF(&expired);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	zephir_create_array(&_0, 1, 0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_1);
	zephir_create_array(&_1, 1, 0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_2);
	zephir_time(&_2);
	zephir_array_update_string(&_1, SL("<"), &_2, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_0, SL("expires"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD(&expired, this_ptr, "load", NULL, 0, &_0);
	zephir_check_call_status();
	_3 = zephir_get_iterator(&expired TSRMLS_CC);
	_3->funcs->rewind(_3 TSRMLS_CC);
	for (;_3->funcs->valid(_3 TSRMLS_CC) == SUCCESS && !EG(exception); _3->funcs->move_forward(_3 TSRMLS_CC)) {
		{
			ZEPHIR_ITERATOR_COPY(&token, _3);
		}
		ZEPHIR_CALL_METHOD(NULL, &token, "remove", NULL, 0);
		zephir_check_call_status();
	}
	zend_iterator_dtor(_3);
	ZEPHIR_MM_RESTORE();

}

/**
 * Generate a new unique token and update the token.
 *
 * @param array fields Fields to save or valid fields
 * @param object extra Extra validation
 * @return mixed
 */
PHP_METHOD(Ice_Auth_Driver_Model_Users_Tokens, update) {

	zephir_fcall_cache_entry *_1 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *fields = NULL, fields_sub, *extra = NULL, extra_sub, __$null, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&fields_sub);
	ZVAL_UNDEF(&extra_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &fields, &extra);

	if (!fields) {
		fields = &fields_sub;
		ZEPHIR_INIT_VAR(fields);
		array_init(fields);
	}
	if (!extra) {
		extra = &extra_sub;
		extra = &__$null;
	}


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "generate", NULL, 0);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, SL("token"), &_0);
	ZEPHIR_RETURN_CALL_PARENT(ice_auth_driver_model_users_tokens_ce, getThis(), "update", &_1, 0, fields);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Generate a new unique token.
 *
 * @return string
 * @uses Text::random()
 */
PHP_METHOD(Ice_Auth_Driver_Model_Users_Tokens, generate) {

	zval _6;
	zval token, _4, _0$$3, _1$$3;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_2 = NULL, *_3 = NULL, *_5 = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&token);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_6);

	ZEPHIR_MM_GROW();

	do {
		ZVAL_LONG(&_0$$3, 16);
		ZEPHIR_CALL_FUNCTION(&_1$$3, "openssl_random_pseudo_bytes", &_2, 42, &_0$$3);
		zephir_check_call_status();
		ZEPHIR_CALL_FUNCTION(&token, "bin2hex", &_3, 43, &_1$$3);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&_6);
		zephir_create_array(&_6, 1, 0 TSRMLS_CC);
		zephir_array_update_string(&_6, SL("token"), &token, PH_COPY | PH_SEPARATE);
		ZEPHIR_CALL_STATIC(&_4, "findone", &_5, 0, &_6);
		zephir_check_call_status();
	} while (zephir_is_true(&_4));
	RETURN_CCTOR(&token);

}


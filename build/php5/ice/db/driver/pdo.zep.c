
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/string.h"
#include "kernel/array.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/concat.h"
#include "ext/date/php_date.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"


/**
 * Pdo driver.
 *
 * @package     Ice/Db
 * @category    Component
 * @author      Ice Team
 * @copyright   (c) 2014-2018 Ice Team
 * @license     http://iceframework.org/license
 */
ZEPHIR_INIT_CLASS(Ice_Db_Driver_Pdo) {

	ZEPHIR_REGISTER_CLASS(Ice\\Db\\Driver, Pdo, ice, db_driver_pdo, ice_db_driver_pdo_method_entry, 0);

	zend_declare_property_string(ice_db_driver_pdo_ce, SL("id"), "id", ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_string(ice_db_driver_pdo_ce, SL("type"), "SQL", ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(ice_db_driver_pdo_ce, SL("error"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(ice_db_driver_pdo_ce, SL("client"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(ice_db_driver_pdo_ce TSRMLS_CC, 1, ice_db_dbinterface_ce);
	return SUCCESS;

}

PHP_METHOD(Ice_Db_Driver_Pdo, getId) {

	

	RETURN_MEMBER(getThis(), "id");

}

PHP_METHOD(Ice_Db_Driver_Pdo, getType) {

	

	RETURN_MEMBER(getThis(), "type");

}

PHP_METHOD(Ice_Db_Driver_Pdo, getClient) {

	

	RETURN_MEMBER(getThis(), "client");

}

/**
 * Instantiate pdo connection.
 *
 * @param string dsn
 * @param string user
 * @param string password
 * @param array options
 */
PHP_METHOD(Ice_Db_Driver_Pdo, __construct) {

	zend_class_entry *_9;
	zend_bool _2;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *options = NULL;
	zval *dsn_param = NULL, *user_param = NULL, *password_param = NULL, *options_param = NULL, *parts = NULL, *pdo = NULL, *_0, _1, *_3, _4, *_5 = NULL, *_7, *_8 = NULL;
	zval *dsn = NULL, *user = NULL, *password = NULL, *_6$$3;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 3, &dsn_param, &user_param, &password_param, &options_param);

	zephir_get_strval(dsn, dsn_param);
	if (!user_param) {
		ZEPHIR_INIT_VAR(user);
		ZVAL_EMPTY_STRING(user);
	} else {
		zephir_get_strval(user, user_param);
	}
	if (!password_param) {
		ZEPHIR_INIT_VAR(password);
		ZVAL_EMPTY_STRING(password);
	} else {
		zephir_get_strval(password, password_param);
	}
	if (!options_param) {
		ZEPHIR_INIT_VAR(options);
		array_init(options);
	} else {
		zephir_get_arrval(options, options_param);
	}


	ZEPHIR_INIT_VAR(parts);
	ZVAL_NULL(parts);
	ZEPHIR_INIT_VAR(_0);
	ZEPHIR_SINIT_VAR(_1);
	ZVAL_STRING(&_1, "/^.+?(?:dbname|database)=(.+?)(?=;|$)/i", 0);
	zephir_preg_match(_0, &_1, dsn, parts, 0, 0 , 0  TSRMLS_CC);
	_2 = zephir_array_isset_long(parts, 0);
	if (_2) {
		zephir_array_fetch_long(&_3, parts, 0, PH_NOISY | PH_READONLY, "ice/db/driver/pdo.zep", 40 TSRMLS_CC);
		ZEPHIR_SINIT_VAR(_4);
		ZVAL_STRING(&_4, ":", 0);
		ZEPHIR_CALL_FUNCTION(&_5, "strstr", NULL, 76, _3, &_4, ZEPHIR_GLOBAL(global_true));
		zephir_check_call_status();
		_2 = ZEPHIR_IS_STRING(_5, "mysql");
	}
	if (_2) {
		ZEPHIR_INIT_VAR(_6$$3);
		ZEPHIR_CONCAT_VS(_6$$3, dsn, ";charset=utf8");
		ZEPHIR_CPY_WRT(dsn, _6$$3);
	}
	ZEPHIR_INIT_VAR(pdo);
	ZVAL_STRING(pdo, "Pdo", 1);
	ZEPHIR_INIT_VAR(_7);
	zephir_fetch_safe_class(_8, pdo);
		_9 = zend_fetch_class(Z_STRVAL_P(_8), Z_STRLEN_P(_8), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
	object_init_ex(_7, _9);
	ZEPHIR_CALL_METHOD(NULL, _7, "__construct", NULL, 0, dsn, user, password, options);
	zephir_check_call_status();
	zephir_update_property_this(getThis(), SL("client"), _7 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Get the id value.
 *
 * @param string id
 * @return int
 */
PHP_METHOD(Ice_Db_Driver_Pdo, getIdValue) {

	zval *id;

	zephir_fetch_params(0, 1, 0, &id);



	RETURN_LONG(zephir_get_intval(id));

}

/**
 * Get a date time object.
 *
 * @param mixed value
 * @param boolean model
 * @return object
 */
PHP_METHOD(Ice_Db_Driver_Pdo, getDateTime) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *value = NULL, *model = NULL, *date = NULL, *_0$$3, *_1$$4;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &value, &model);

	if (!value) {
		ZEPHIR_CPY_WRT(value, ZEPHIR_GLOBAL(global_null));
	} else {
		ZEPHIR_SEPARATE_PARAM(value);
	}
	if (!model) {
		model = ZEPHIR_GLOBAL(global_false);
	}


	if (Z_TYPE_P(value) == IS_LONG) {
		ZEPHIR_INIT_VAR(_0$$3);
		ZEPHIR_CONCAT_SV(_0$$3, "@", value);
		ZEPHIR_CPY_WRT(value, _0$$3);
	}
	ZEPHIR_INIT_VAR(date);
	object_init_ex(date, php_date_get_date_ce());
	ZEPHIR_CALL_METHOD(NULL, date, "__construct", NULL, 0, value);
	zephir_check_call_status();
	if (zephir_is_true(model)) {
		ZEPHIR_INIT_VAR(_1$$4);
		ZVAL_STRING(_1$$4, "Y-m-d H:i:s.u", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_RETURN_CALL_METHOD(date, "format", NULL, 0, _1$$4);
		zephir_check_temp_parameter(_1$$4);
		zephir_check_call_status();
		RETURN_MM();
	}
	RETURN_CCTOR(date);

}

/**
 * Find one row that match criteria.
 *
 * @param string from Table name
 * @param mixed filters Filters to create WHERE conditions
 * @param array options Options to limit/group results
 * @param array fields Fields to retrieve, if not specified get all
 * @return Arr|false
 */
PHP_METHOD(Ice_Db_Driver_Pdo, findOne) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *options = NULL, *fields = NULL;
	zval *from_param = NULL, *filters = NULL, *options_param = NULL, *fields_param = NULL, *result = NULL, *_0, *_1, *_2 = NULL, *_3 = NULL, *_4;
	zval *from = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 3, &from_param, &filters, &options_param, &fields_param);

	if (UNEXPECTED(Z_TYPE_P(from_param) != IS_STRING && Z_TYPE_P(from_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'from' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(from_param) == IS_STRING)) {
		zephir_get_strval(from, from_param);
	} else {
		ZEPHIR_INIT_VAR(from);
		ZVAL_EMPTY_STRING(from);
	}
	if (!filters) {
		ZEPHIR_INIT_VAR(filters);
		array_init(filters);
	}
	if (!options_param) {
		ZEPHIR_INIT_VAR(options);
		array_init(options);
	} else {
		zephir_get_arrval(options, options_param);
	}
	if (!fields_param) {
		ZEPHIR_INIT_VAR(fields);
		array_init(fields);
	} else {
		zephir_get_arrval(fields, fields_param);
	}


	ZEPHIR_INIT_VAR(_0);
	ZVAL_LONG(_0, 1);
	zephir_array_update_string(&options, SL("limit"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD(&result, this_ptr, "select", NULL, 0, from, filters, options, fields);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_1);
	ZEPHIR_CALL_METHOD(&_2, result, "rowcount", NULL, 0);
	zephir_check_call_status();
	if (zephir_is_true(_2)) {
		object_init_ex(_1, ice_arr_ce);
		ZEPHIR_INIT_VAR(_4);
		ZVAL_LONG(_4, 2);
		ZEPHIR_CALL_METHOD(&_3, result, "fetch", NULL, 0, _4);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, _1, "__construct", NULL, 5, _3);
		zephir_check_call_status();
	} else {
		ZVAL_BOOL(_1, 0);
	}
	RETURN_CCTOR(_1);

}

/**
 * Find all records that match criteria.
 *
 * <pre><code>
 *  //SELECT * FROM users WHERE a=1 and b="q"
 *  $db->find("users", array("a" => 1, "b" => "q"));
 * 
 *  //SELECT * FROM users WHERE age>33 
 *  $db->find("users", array("age" => array(">" => 33)));
 * 
 *  //SELECT * FROM users WHERE a=1 or b=2 
 *  $db->find("users", array("OR" => array(array("a" => 1), array("b" => 2))));
 * </code></pre>
 *
 * @param string from Table name
 * @param mixed filters Filters to create WHERE conditions
 * @param array options Options to limit/group results
 * @param array fields Fields to retrieve, if not specified get all
 * @return Arr
 */
PHP_METHOD(Ice_Db_Driver_Pdo, find) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *options = NULL, *fields = NULL;
	zval *from_param = NULL, *filters = NULL, *options_param = NULL, *fields_param = NULL, *result = NULL, *_0 = NULL, *_1;
	zval *from = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 3, &from_param, &filters, &options_param, &fields_param);

	if (UNEXPECTED(Z_TYPE_P(from_param) != IS_STRING && Z_TYPE_P(from_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'from' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(from_param) == IS_STRING)) {
		zephir_get_strval(from, from_param);
	} else {
		ZEPHIR_INIT_VAR(from);
		ZVAL_EMPTY_STRING(from);
	}
	if (!filters) {
		ZEPHIR_INIT_VAR(filters);
		array_init(filters);
	}
	if (!options_param) {
		ZEPHIR_INIT_VAR(options);
		array_init(options);
	} else {
		zephir_get_arrval(options, options_param);
	}
	if (!fields_param) {
		ZEPHIR_INIT_VAR(fields);
		array_init(fields);
	} else {
		zephir_get_arrval(fields, fields_param);
	}


	ZEPHIR_CALL_METHOD(&result, this_ptr, "select", NULL, 0, from, filters, options, fields);
	zephir_check_call_status();
	object_init_ex(return_value, ice_arr_ce);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_LONG(_1, 2);
	ZEPHIR_CALL_METHOD(&_0, result, "fetchall", NULL, 0, _1);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 5, _0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Prepare SQL WHERE condition.
 *
 * @params mixed filters
 * @params array values
 */
PHP_METHOD(Ice_Db_Driver_Pdo, where) {

	HashTable *_3$$4, *_7$$5, *_14$$14;
	HashPosition _2$$4, _6$$5, _13$$14;
	zend_long ZEPHIR_LAST_CALL_STATUS, _0$$3;
	zephir_fcall_cache_entry *_9 = NULL, *_10 = NULL;
	zval *values = NULL, *_5$$8 = NULL;
	zval *filters = NULL, *values_param = NULL, *and = NULL, *data = NULL, *operator = NULL, *key = NULL, *item = NULL, *value = NULL, *or = NULL, *is = NULL, *index = NULL, *i = NULL, *sql = NULL, *condition = NULL, *_1, **_4$$4, *_21$$4, *tmp$$8 = NULL, **_8$$5, *_11$$10 = NULL, *_12$$12 = NULL, *j$$14 = NULL, *id$$14 = NULL, *ids$$14 = NULL, **_15$$14, *_18$$14 = NULL, *_16$$15 = NULL, *_17$$15 = NULL, *_19$$20 = NULL, *_20$$20 = NULL, *_22$$21;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &filters, &values_param);

	if (!filters) {
		ZEPHIR_INIT_VAR(filters);
		array_init(filters);
	} else {
		ZEPHIR_SEPARATE_PARAM(filters);
	}
	if (!values_param) {
		ZEPHIR_INIT_VAR(values);
		array_init(values);
	} else {
		zephir_get_arrval(values, values_param);
	}


	ZEPHIR_INIT_VAR(and);
	array_init(and);
	ZEPHIR_INIT_VAR(sql);
	ZVAL_STRING(sql, "", 1);
	ZEPHIR_INIT_VAR(i);
	ZVAL_STRING(i, "", 1);
	if (zephir_is_numeric(filters)) {
		_0$$3 = zephir_get_intval(filters);
		ZEPHIR_INIT_NVAR(filters);
		ZVAL_LONG(filters, _0$$3);
	}
	ZEPHIR_INIT_VAR(_1);
	zephir_gettype(_1, filters TSRMLS_CC);
	do {
		if (ZEPHIR_IS_STRING(_1, "array")) {
			zephir_is_iterable(filters, &_3$$4, &_2$$4, 0, 0, "ice/db/driver/pdo.zep", 228);
			for (
			  ; zend_hash_get_current_data_ex(_3$$4, (void**) &_4$$4, &_2$$4) == SUCCESS
			  ; zend_hash_move_forward_ex(_3$$4, &_2$$4)
			) {
				ZEPHIR_GET_HMKEY(operator, _3$$4, _2$$4);
				ZEPHIR_GET_HVALUE(data, _4$$4);
				do {
					if (ZEPHIR_IS_STRING(operator, "OR") || ZEPHIR_IS_STRING(operator, "or") || ZEPHIR_IS_STRING(operator, "$or")) {
						ZEPHIR_INIT_NVAR(or);
						array_init(or);
						ZEPHIR_INIT_NVAR(operator);
						ZVAL_STRING(operator, "OR", 1);
						break;
					}
					if (ZEPHIR_IS_STRING(operator, "AND") || ZEPHIR_IS_STRING(operator, "and") || ZEPHIR_IS_STRING(operator, "$and")) {
						ZEPHIR_INIT_NVAR(operator);
						ZVAL_STRING(operator, "AND", 1);
						break;
					}
					ZEPHIR_CPY_WRT(tmp$$8, data);
					ZEPHIR_INIT_NVAR(data);
					zephir_create_array(data, 1, 0 TSRMLS_CC);
					ZEPHIR_INIT_NVAR(_5$$8);
					zephir_create_array(_5$$8, 1, 0 TSRMLS_CC);
					zephir_array_update_zval(&_5$$8, operator, &tmp$$8, PH_COPY);
					zephir_array_update_string(&data, SL("AND"), &_5$$8, PH_COPY | PH_SEPARATE);
					ZEPHIR_INIT_NVAR(operator);
					ZVAL_STRING(operator, "AND", 1);
					break;
				} while(0);

				zephir_is_iterable(data, &_7$$5, &_6$$5, 0, 0, "ice/db/driver/pdo.zep", 224);
				for (
				  ; zend_hash_get_current_data_ex(_7$$5, (void**) &_8$$5, &_6$$5) == SUCCESS
				  ; zend_hash_move_forward_ex(_7$$5, &_6$$5)
				) {
					ZEPHIR_GET_HVALUE(item, _8$$5);
					ZEPHIR_MAKE_REF(item);
					ZEPHIR_CALL_FUNCTION(&key, "key", &_9, 77, item);
					ZEPHIR_UNREF(item);
					zephir_check_call_status();
					ZEPHIR_MAKE_REF(item);
					ZEPHIR_CALL_FUNCTION(&value, "current", &_10, 74, item);
					ZEPHIR_UNREF(item);
					zephir_check_call_status();
					if (Z_TYPE_P(value) == IS_ARRAY) {
						ZEPHIR_MAKE_REF(value);
						ZEPHIR_CALL_FUNCTION(&is, "key", &_9, 77, value);
						ZEPHIR_UNREF(value);
						zephir_check_call_status();
						ZEPHIR_MAKE_REF(value);
						ZEPHIR_CALL_FUNCTION(&_11$$10, "current", &_10, 74, value);
						ZEPHIR_UNREF(value);
						zephir_check_call_status();
						ZEPHIR_CPY_WRT(value, _11$$10);
					} else {
						ZEPHIR_INIT_NVAR(is);
						ZVAL_STRING(is, "=", 1);
					}
					do {
						ZEPHIR_INIT_NVAR(index);
						ZEPHIR_CONCAT_SVV(index, ":", key, i);
						ZEPHIR_INIT_LNVAR(_12$$12);
						if (zephir_is_true(i)) {
							ZEPHIR_INIT_NVAR(_12$$12);
							ZVAL_LONG(_12$$12, (zephir_get_intval(i) + 1));
						} else {
							ZEPHIR_INIT_NVAR(_12$$12);
							ZVAL_LONG(_12$$12, 1);
						}
						ZEPHIR_CPY_WRT(i, _12$$12);
					} while (zephir_array_isset(values, index));
					do {
						if (ZEPHIR_IS_STRING(is, "IN") || ZEPHIR_IS_STRING(is, "in") || ZEPHIR_IS_STRING(is, "$in")) {
							if (Z_TYPE_P(value) == IS_ARRAY) {
								ZEPHIR_INIT_NVAR(ids$$14);
								array_init(ids$$14);
								zephir_is_iterable(value, &_14$$14, &_13$$14, 0, 0, "ice/db/driver/pdo.zep", 199);
								for (
								  ; zend_hash_get_current_data_ex(_14$$14, (void**) &_15$$14, &_13$$14) == SUCCESS
								  ; zend_hash_move_forward_ex(_14$$14, &_13$$14)
								) {
									ZEPHIR_GET_HMKEY(j$$14, _14$$14, _13$$14);
									ZEPHIR_GET_HVALUE(id$$14, _15$$14);
									ZEPHIR_INIT_LNVAR(_16$$15);
									ZEPHIR_CONCAT_VV(_16$$15, index, j$$14);
									zephir_array_append(&ids$$14, _16$$15, PH_SEPARATE, "ice/db/driver/pdo.zep", 195);
									ZEPHIR_INIT_LNVAR(_17$$15);
									ZEPHIR_CONCAT_VV(_17$$15, index, j$$14);
									zephir_array_update_zval(&values, _17$$15, &id$$14, PH_COPY | PH_SEPARATE);
								}
								ZEPHIR_INIT_NVAR(_18$$14);
								zephir_fast_join_str(_18$$14, SL(", "), ids$$14 TSRMLS_CC);
								ZEPHIR_INIT_NVAR(value);
								ZEPHIR_CONCAT_SVS(value, "(", _18$$14, ")");
							}
							ZEPHIR_INIT_NVAR(condition);
							ZEPHIR_CONCAT_SVSVSV(condition, "`", key, "` ", is, " ", value);
							break;
						}
						if (ZEPHIR_IS_STRING(is, "IS") || ZEPHIR_IS_STRING(is, "is") || ZEPHIR_IS_STRING(is, "IS NOT") || ZEPHIR_IS_STRING(is, "is not")) {
							ZEPHIR_INIT_NVAR(condition);
							ZEPHIR_CONCAT_SVSVSV(condition, "`", key, "` ", is, " ", value);
							break;
						}
						ZEPHIR_INIT_NVAR(condition);
						ZEPHIR_CONCAT_SVSVSV(condition, "`", key, "` ", is, " ", index);
						zephir_array_update_zval(&values, index, &value, PH_COPY | PH_SEPARATE);
						break;
					} while(0);

					if (ZEPHIR_IS_STRING(operator, "AND")) {
						zephir_array_append(&and, condition, PH_SEPARATE, "ice/db/driver/pdo.zep", 218);
					} else {
						zephir_array_append(&or, condition, PH_SEPARATE, "ice/db/driver/pdo.zep", 220);
					}
				}
				if (ZEPHIR_IS_STRING(operator, "OR")) {
					ZEPHIR_INIT_NVAR(_19$$20);
					zephir_fast_join_str(_19$$20, SL(" OR "), or TSRMLS_CC);
					ZEPHIR_INIT_LNVAR(_20$$20);
					ZEPHIR_CONCAT_SVS(_20$$20, "(", _19$$20, ")");
					zephir_array_append(&and, _20$$20, PH_SEPARATE, "ice/db/driver/pdo.zep", 225);
				}
			}
			ZEPHIR_INIT_VAR(_21$$4);
			zephir_fast_join_str(_21$$4, SL(" AND "), and TSRMLS_CC);
			zephir_concat_self(&sql, _21$$4 TSRMLS_CC);
			break;
		}
		if (ZEPHIR_IS_STRING(_1, "integer")) {
			ZEPHIR_INIT_VAR(_22$$21);
			ZEPHIR_CONCAT_SV(_22$$21, "`id` = ", filters);
			zephir_concat_self(&sql, _22$$21 TSRMLS_CC);
			break;
		}
		if (ZEPHIR_IS_STRING(_1, "string")) {
			zephir_concat_self(&sql, filters TSRMLS_CC);
			break;
		}
		zephir_concat_self_str(&sql, SL("TRUE") TSRMLS_CC);
		break;
	} while(0);

	zephir_create_array(return_value, 2, 0 TSRMLS_CC);
	zephir_array_fast_append(return_value, sql);
	zephir_array_fast_append(return_value, values);
	RETURN_MM();

}

/**
 * SELECT record(s) that match criteria.
 *
 * @param string from Table name
 * @param mixed filters Filters to create WHERE conditions
 * @param array options Options to limit/group results
 * @param array fields Fields to retrieve, if not specified get all
 */
PHP_METHOD(Ice_Db_Driver_Pdo, select) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *options = NULL, *fields = NULL;
	zval *from_param = NULL, *filters = NULL, *options_param = NULL, *fields_param = NULL, *columns = NULL, *sql = NULL, *filtered = NULL, *values = NULL, *query = NULL, *_0, *_11, *_12 = NULL, *_1$$5, *_2$$5, *_3$$5, *_4$$6, *_5$$6, *_6$$6, *_7$$7, *_8$$7, *_9$$8, *_10$$8;
	zval *from = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 3, &from_param, &filters, &options_param, &fields_param);

	if (UNEXPECTED(Z_TYPE_P(from_param) != IS_STRING && Z_TYPE_P(from_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'from' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(from_param) == IS_STRING)) {
		zephir_get_strval(from, from_param);
	} else {
		ZEPHIR_INIT_VAR(from);
		ZVAL_EMPTY_STRING(from);
	}
	if (!filters) {
		ZEPHIR_INIT_VAR(filters);
		array_init(filters);
	}
	if (!options_param) {
		ZEPHIR_INIT_VAR(options);
		array_init(options);
	} else {
		zephir_get_arrval(options, options_param);
	}
	if (!fields_param) {
		ZEPHIR_INIT_VAR(fields);
		array_init(fields);
	} else {
		zephir_get_arrval(fields, fields_param);
	}


	if (zephir_fast_count_int(fields TSRMLS_CC)) {
		ZEPHIR_INIT_VAR(columns);
		zephir_fast_join_str(columns, SL(", "), fields TSRMLS_CC);
	} else {
		ZEPHIR_INIT_NVAR(columns);
		ZVAL_STRING(columns, "*", 1);
	}
	ZEPHIR_CALL_METHOD(&filtered, this_ptr, "where", NULL, 0, filters);
	zephir_check_call_status();
	zephir_array_fetch_long(&_0, filtered, 0, PH_NOISY | PH_READONLY, "ice/db/driver/pdo.zep", 263 TSRMLS_CC);
	ZEPHIR_INIT_VAR(sql);
	ZEPHIR_CONCAT_SVSVSV(sql, "SELECT ", columns, " FROM `", from, "` WHERE ", _0);
	ZEPHIR_OBS_VAR(values);
	zephir_array_fetch_long(&values, filtered, 1, PH_NOISY, "ice/db/driver/pdo.zep", 264 TSRMLS_CC);
	if (zephir_array_isset_string(options, SS("group"))) {
		ZEPHIR_INIT_VAR(_1$$5);
		zephir_array_fetch_string(&_2$$5, options, SL("group"), PH_NOISY | PH_READONLY, "ice/db/driver/pdo.zep", 267 TSRMLS_CC);
		zephir_fast_join_str(_1$$5, SL(", "), _2$$5 TSRMLS_CC);
		ZEPHIR_INIT_VAR(_3$$5);
		ZEPHIR_CONCAT_SV(_3$$5, " GROUP BY ", _1$$5);
		zephir_concat_self(&sql, _3$$5 TSRMLS_CC);
	}
	if (zephir_array_isset_string(options, SS("order"))) {
		ZEPHIR_INIT_VAR(_4$$6);
		zephir_array_fetch_string(&_5$$6, options, SL("order"), PH_NOISY | PH_READONLY, "ice/db/driver/pdo.zep", 270 TSRMLS_CC);
		zephir_fast_join_str(_4$$6, SL(", "), _5$$6 TSRMLS_CC);
		ZEPHIR_INIT_VAR(_6$$6);
		ZEPHIR_CONCAT_SV(_6$$6, " ORDER BY ", _4$$6);
		zephir_concat_self(&sql, _6$$6 TSRMLS_CC);
	}
	if (zephir_array_isset_string(options, SS("limit"))) {
		zephir_array_fetch_string(&_7$$7, options, SL("limit"), PH_NOISY | PH_READONLY, "ice/db/driver/pdo.zep", 273 TSRMLS_CC);
		ZEPHIR_INIT_VAR(_8$$7);
		ZEPHIR_CONCAT_SV(_8$$7, " LIMIT ", _7$$7);
		zephir_concat_self(&sql, _8$$7 TSRMLS_CC);
	}
	if (zephir_array_isset_string(options, SS("offset"))) {
		zephir_array_fetch_string(&_9$$8, options, SL("offset"), PH_NOISY | PH_READONLY, "ice/db/driver/pdo.zep", 276 TSRMLS_CC);
		ZEPHIR_INIT_VAR(_10$$8);
		ZEPHIR_CONCAT_SV(_10$$8, " OFFSET ", _9$$8);
		zephir_concat_self(&sql, _10$$8 TSRMLS_CC);
	}
	_11 = zephir_fetch_nproperty_this(this_ptr, SL("client"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&query, _11, "prepare", NULL, 0, sql);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, query, "execute", NULL, 0, values);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_12, query, "errorinfo", NULL, 0);
	zephir_check_call_status();
	zephir_update_property_this(getThis(), SL("error"), _12 TSRMLS_CC);
	RETURN_CCTOR(query);

}

/**
 * INSERT record into table.
 *
 * @param string from Table name
 * @param array fields Fields to insert, keys are the column names
 */
PHP_METHOD(Ice_Db_Driver_Pdo, insert) {

	HashTable *_1;
	HashPosition _0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *fields = NULL;
	zval *from_param = NULL, *fields_param = NULL, *key = NULL, *value = NULL, *columns = NULL, *values = NULL, *sql = NULL, *query = NULL, *status = NULL, **_2, *_5, *_6, *_7, *_8, *_9 = NULL, *_3$$3 = NULL, *_4$$3 = NULL;
	zval *from = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &from_param, &fields_param);

	if (UNEXPECTED(Z_TYPE_P(from_param) != IS_STRING && Z_TYPE_P(from_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'from' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(from_param) == IS_STRING)) {
		zephir_get_strval(from, from_param);
	} else {
		ZEPHIR_INIT_VAR(from);
		ZVAL_EMPTY_STRING(from);
	}
	if (!fields_param) {
		ZEPHIR_INIT_VAR(fields);
		array_init(fields);
	} else {
		zephir_get_arrval(fields, fields_param);
	}


	ZEPHIR_INIT_VAR(columns);
	array_init(columns);
	ZEPHIR_INIT_VAR(values);
	array_init(values);
	zephir_is_iterable(fields, &_1, &_0, 0, 0, "ice/db/driver/pdo.zep", 306);
	for (
	  ; zend_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
	  ; zend_hash_move_forward_ex(_1, &_0)
	) {
		ZEPHIR_GET_HMKEY(key, _1, _0);
		ZEPHIR_GET_HVALUE(value, _2);
		ZEPHIR_INIT_LNVAR(_3$$3);
		ZEPHIR_CONCAT_SVS(_3$$3, "`", key, "`");
		zephir_array_append(&columns, _3$$3, PH_SEPARATE, "ice/db/driver/pdo.zep", 302);
		ZEPHIR_INIT_LNVAR(_4$$3);
		ZEPHIR_CONCAT_SV(_4$$3, ":", key);
		zephir_array_update_zval(&values, _4$$3, &value, PH_COPY | PH_SEPARATE);
	}
	ZEPHIR_INIT_VAR(_5);
	zephir_fast_join_str(_5, SL(", "), columns TSRMLS_CC);
	ZEPHIR_INIT_VAR(_6);
	ZEPHIR_INIT_VAR(_7);
	zephir_array_keys(_7, values TSRMLS_CC);
	zephir_fast_join_str(_6, SL(", "), _7 TSRMLS_CC);
	ZEPHIR_INIT_VAR(sql);
	ZEPHIR_CONCAT_SVSVSVS(sql, "INSERT INTO `", from, "` (", _5, ") VALUES (", _6, ")");
	_8 = zephir_fetch_nproperty_this(this_ptr, SL("client"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&query, _8, "prepare", NULL, 0, sql);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&status, query, "execute", NULL, 0, values);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_9, query, "errorinfo", NULL, 0);
	zephir_check_call_status();
	zephir_update_property_this(getThis(), SL("error"), _9 TSRMLS_CC);
	RETURN_CCTOR(status);

}

/**
 * UPDATE records in the table.
 *
 * @param string from Table name
 * @param mixed filters Filters to create WHERE conditions
 * @param array fields Fields to update, keys are the column names
 */
PHP_METHOD(Ice_Db_Driver_Pdo, update) {

	HashTable *_1;
	HashPosition _0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *fields = NULL;
	zval *from_param = NULL, *filters = NULL, *fields_param = NULL, *key = NULL, *value = NULL, *columns = NULL, *values = NULL, *filtered = NULL, *sql = NULL, *query = NULL, *status = NULL, **_2, *_5, *_6, *_7, *_8, *_9, *_10 = NULL, *_3$$3 = NULL, *_4$$3 = NULL;
	zval *from = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &from_param, &filters, &fields_param);

	if (UNEXPECTED(Z_TYPE_P(from_param) != IS_STRING && Z_TYPE_P(from_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'from' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(from_param) == IS_STRING)) {
		zephir_get_strval(from, from_param);
	} else {
		ZEPHIR_INIT_VAR(from);
		ZVAL_EMPTY_STRING(from);
	}
	if (!filters) {
		ZEPHIR_INIT_VAR(filters);
		array_init(filters);
	}
	if (!fields_param) {
		ZEPHIR_INIT_VAR(fields);
		array_init(fields);
	} else {
		zephir_get_arrval(fields, fields_param);
	}


	ZEPHIR_INIT_VAR(columns);
	array_init(columns);
	ZEPHIR_INIT_VAR(values);
	array_init(values);
	zephir_is_iterable(fields, &_1, &_0, 0, 0, "ice/db/driver/pdo.zep", 333);
	for (
	  ; zend_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
	  ; zend_hash_move_forward_ex(_1, &_0)
	) {
		ZEPHIR_GET_HMKEY(key, _1, _0);
		ZEPHIR_GET_HVALUE(value, _2);
		ZEPHIR_INIT_LNVAR(_3$$3);
		ZEPHIR_CONCAT_SV(_3$$3, ":", key);
		zephir_array_update_zval(&values, _3$$3, &value, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_LNVAR(_4$$3);
		ZEPHIR_CONCAT_SVSV(_4$$3, "`", key, "` = :", key);
		zephir_array_append(&columns, _4$$3, PH_SEPARATE, "ice/db/driver/pdo.zep", 330);
	}
	ZEPHIR_CALL_METHOD(&filtered, this_ptr, "where", NULL, 0, filters, values);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_5);
	zephir_fast_join_str(_5, SL(", "), columns TSRMLS_CC);
	zephir_array_fetch_long(&_6, filtered, 0, PH_NOISY | PH_READONLY, "ice/db/driver/pdo.zep", 334 TSRMLS_CC);
	ZEPHIR_INIT_VAR(sql);
	ZEPHIR_CONCAT_SVSVSV(sql, "UPDATE `", from, "` SET ", _5, " WHERE ", _6);
	ZEPHIR_INIT_VAR(_7);
	zephir_array_fetch_long(&_8, filtered, 1, PH_NOISY | PH_READONLY, "ice/db/driver/pdo.zep", 335 TSRMLS_CC);
	zephir_fast_array_merge(_7, &(values), &(_8) TSRMLS_CC);
	ZEPHIR_CPY_WRT(values, _7);
	_9 = zephir_fetch_nproperty_this(this_ptr, SL("client"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&query, _9, "prepare", NULL, 0, sql);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&status, query, "execute", NULL, 0, values);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_10, query, "errorinfo", NULL, 0);
	zephir_check_call_status();
	zephir_update_property_this(getThis(), SL("error"), _10 TSRMLS_CC);
	RETURN_CCTOR(status);

}

/**
 * Remove records from the table.
 *
 * @param string from Table name
 * @param mixed filters Filters to create WHERE conditions
 */
PHP_METHOD(Ice_Db_Driver_Pdo, remove) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *from_param = NULL, *filters = NULL, *filtered = NULL, *sql = NULL, *values = NULL, *query = NULL, *status = NULL, *_0, *_1, *_2 = NULL;
	zval *from = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &from_param, &filters);

	if (UNEXPECTED(Z_TYPE_P(from_param) != IS_STRING && Z_TYPE_P(from_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'from' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(from_param) == IS_STRING)) {
		zephir_get_strval(from, from_param);
	} else {
		ZEPHIR_INIT_VAR(from);
		ZVAL_EMPTY_STRING(from);
	}
	if (!filters) {
		ZEPHIR_INIT_VAR(filters);
		array_init(filters);
	}


	ZEPHIR_CALL_METHOD(&filtered, this_ptr, "where", NULL, 0, filters);
	zephir_check_call_status();
	zephir_array_fetch_long(&_0, filtered, 0, PH_NOISY | PH_READONLY, "ice/db/driver/pdo.zep", 354 TSRMLS_CC);
	ZEPHIR_INIT_VAR(sql);
	ZEPHIR_CONCAT_SVSV(sql, "DELETE FROM `", from, "` WHERE ", _0);
	ZEPHIR_OBS_VAR(values);
	zephir_array_fetch_long(&values, filtered, 1, PH_NOISY, "ice/db/driver/pdo.zep", 355 TSRMLS_CC);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("client"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&query, _1, "prepare", NULL, 0, sql);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&status, query, "execute", NULL, 0, values);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_2, query, "errorinfo", NULL, 0);
	zephir_check_call_status();
	zephir_update_property_this(getThis(), SL("error"), _2 TSRMLS_CC);
	RETURN_CCTOR(status);

}

/**
 * Get last inserted ID.
 *
 * @return int
 */
PHP_METHOD(Ice_Db_Driver_Pdo, getLastInsertId) {

	zval *_0, *_1 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("client"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&_1, _0, "lastinsertid", NULL, 0);
	zephir_check_call_status();
	RETURN_MM_LONG(zephir_get_intval(_1));

}

/**
 * Get an error message.
 *
 * @return mixed
 */
PHP_METHOD(Ice_Db_Driver_Pdo, getError) {

	zval *error = NULL, *_0;


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("error"), PH_NOISY_CC);
	zephir_array_isset_long_fetch(&error, _0, 0, 1 TSRMLS_CC);
	RETURN_CTORW(error);

}


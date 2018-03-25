
namespace Ice\Auth\Driver\Model;

use Ice\Mvc\Model;

/**
 * Model Roles.
 *
 * @package     Ice/Auth
 * @category    Model
 * @author      Ice Team
 * @copyright   (c) 2014-2018 Ice Team
 * @license     http://iceframework.org/license
 */
class Roles extends Model
{

    /**
     * Initialize role's relations.
     *
     * @return void
     */
    public function initialize()
    {
        this->hasMany(this->getIdKey(), "Ice\\Auth\\Driver\\Model\\Roles\\Users", "role_id", [
            "alias": "RolesUsers"
        ]);
    }
}

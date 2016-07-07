<?php
$uid = '1414';
$result = db_query("select name, mail, field_job_title_value from users u left join field_data_field_job_title fdfjt on u.uid = fdfjt.entity_id and fdfjt.entity_type = 'user' where uid = $uid");

var_dump($result);

?>
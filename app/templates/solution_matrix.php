<?php

// get the csv file
$file = fopen("contract_solutions.csv","r");

while(!feof($file)) {
  $rows[] = fgetcsv($file);
}
// var_dump($rows);
$sql = null;
for ($i = 1; $i < count($rows); $i++) {
  if (!is_null($rows[$i][0])) {

    $sql .= "INSERT INTO tbContractSolutions ({$rows[0][0]}, {$rows[0][1]}, {$rows[0][2]}, {$rows[0][4]}, {$rows[0][5]}, {$rows[0][6]}, {$rows[0][7]}, {$rows[0][8]}, {$rows[0][9]}, {$rows[0][10]})
          VALUES (\"{$rows[$i][0]}\",
                  {$rows[$i][1]},
                  \"{$rows[$i][2]}\",
                  {$rows[$i][4]},
                  \"{$rows[$i][5]}\",
                  \"{$rows[$i][6]}\",
                  \"{$rows[$i][7]}\",
                  \"{$rows[$i][8]}\",
                  \"{$rows[$i][9]}\",
                  \"{$rows[$i][10]}\");\r\n
          INSERT INTO tbContractSolutionToSolutionType (fkContractSolutionId,fkSolutionTypeId)
          VALUES(LAST_INSERT_ID(),{$rows[$i][3]});\r\n";
  }
}

$sql_file = 'contract_solutions.sql';
file_put_contents($sql_file, $sql);
var_dump($sql);

fclose($file);
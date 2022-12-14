--disable_warnings
--disable_query_log
--disable_result_log
--source ../t/test_init.inc
--enable_result_log
--enable_query_log
--enable_warnings
--let $MASTER_1_COMMENT_P_2_1_BACKUP= $MASTER_1_COMMENT_P_2_1
let $MASTER_1_COMMENT_P_2_1=
  PARTITION BY LIST(a % 3) (
    PARTITION pt1 VALUES IN (0) COMMENT='srv "s_2_1", table "ta_r2"',
    PARTITION pt2 VALUES IN (1) COMMENT='srv "s_2_1", table "ta_r3"',
    PARTITION pt3 VALUES IN (2) COMMENT='srv "s_2_1", table "ta_r4"'
  );
--let $CHILD2_1_DROP_TABLES_BACKUP= $CHILD2_1_DROP_TABLES
let $CHILD2_1_DROP_TABLES=
  DROP TABLE IF EXISTS ta_r2 $STR_SEMICOLON
  DROP TABLE IF EXISTS ta_r3 $STR_SEMICOLON
  DROP TABLE IF EXISTS ta_r4;
--let $CHILD2_1_CREATE_TABLES_BACKUP= $CHILD2_1_CREATE_TABLES
let $CHILD2_1_CREATE_TABLES=
  CREATE TABLE ta_r2 (
    a INT,
    b VARCHAR(30),
    PRIMARY KEY(a)
  ) $CHILD2_1_ENGINE $CHILD2_1_CHARSET $STR_SEMICOLON
  CREATE TABLE ta_r3 (
    a INT,
    b VARCHAR(30),
    PRIMARY KEY(a)
  ) $CHILD2_1_ENGINE $CHILD2_1_CHARSET $STR_SEMICOLON
  CREATE TABLE ta_r4 (
    a INT,
    b VARCHAR(30),
    PRIMARY KEY(a)
  ) $CHILD2_1_ENGINE $CHILD2_1_CHARSET;
--let $CHILD2_1_SELECT_TABLES_BACKUP= $CHILD2_1_SELECT_TABLES
let $CHILD2_1_SELECT_TABLES=
  SELECT a, b FROM ta_r2 ORDER BY a $STR_SEMICOLON
  SELECT a, b FROM ta_r3 ORDER BY a $STR_SEMICOLON
  SELECT a, b FROM ta_r4 ORDER BY a;
let $CHILD2_1_SELECT_ARGUMENT1=
  SELECT argument FROM mysql.general_log WHERE argument LIKE '%select %';

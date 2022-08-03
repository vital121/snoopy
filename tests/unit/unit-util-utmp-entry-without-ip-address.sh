#!/bin/bash



### Configure shell and bootstrap
#
set -e
set -u
. `dirname $BASH_SOURCE`/_bootstrap.sh



### Run the mock test
#
VAL_EXPECTED="-"
VAL_SNOOPY=`$SNOOPY_TEST_CLI unit util utmp /dev/tty1 $SNOOPY_CUR_TEST_DIR/unit-util-utmp-testUtmpFile`

snoopy_test_compareValues "$VAL_SNOOPY" "$VAL_EXPECTED"

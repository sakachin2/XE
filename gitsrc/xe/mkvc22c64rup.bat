set log=g:\src\xe\mkvc22c64rup.log
cp  %log% %log%.old
del %log%

echo "***mkvc22c Rel ulib64*"      >>      %log%
call ulib
call mkvc22c64r  /A    2>&1 | tee -a %log%

echo "***mkvc22c Rel xe64***"      >>      %log%
call srcxe
call mkvc22c64r  /A    2>&1 | tee -a %log%

echo "***mkvc22c Rel xsub64*"      >>      %log%
call xsub
call mkvc22call64r /A   2>&1 | tee -a %log%

echo "***mkvc22c Rel xp64***"      >>      %log%
call srcxp
call mkvc22c64r  /A    2>&1 | tee -a %log%

call srcxe

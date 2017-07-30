set log=g:\src\xe\mkvc17c64rup.log
cp  %log% %log%.old
del %log%

echo "***mkvc17c Rel ulib64*"      >>      %log%
call ulib
call mkvc17c64r  /A    2>&1 | tee -a %log%

echo "***mkvc17c Rel xe64***"      >>      %log%
call srcxe
call mkvc17c64r  /A    2>&1 | tee -a %log%

echo "***mkvc17c Rel xsub64*"      >>      %log%
call xsub
call mkvc17call64r /A   2>&1 | tee -a %log%

echo "***mkvc17c Rel xp64***"      >>      %log%
call srcxp
call mkvc17c64r  /A    2>&1 | tee -a %log%

call srcxe

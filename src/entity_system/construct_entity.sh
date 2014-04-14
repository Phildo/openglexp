#!/bin/bash

TMP_FILE=".ENTITY_CONSTRUCTION.tmp"
ACTIVE_FILE=""
FLAG=""

function fileToUnder()
{
  echo $1 | sed -e 's/^[^/]*\///g' -e 's/.h$//'
}
function underToCamel()
{
  echo $1 | gsed -e 's/_\(.\)/\U\1/g' -e 's/^\(.\)/\U\1/'
}


#
#CONSTRUCT ENTITY
#
ACTIVE_FILE="entity.h"
FLAG="ECS_CONSTRUCT_C_FORWARD_DECLS"
touch $TMP_FILE
for i in components/*.h; do
  UNDER=`fileToUnder $i`
  CAMEL=`underToCamel $UNDER`
  echo "class $CAMEL;"  >> $TMP_FILE
done
inject ${FLAG}_START  ${FLAG}_END  $TMP_FILE $ACTIVE_FILE
rm $TMP_FILE

FLAG="ECS_CONSTRUCT_PUBLIC_C_MEMBERS"
touch $TMP_FILE
for i in components/*.h; do
  UNDER=`fileToUnder $i`
  CAMEL=`underToCamel $UNDER`
  echo "$CAMEL* $UNDER;" >> $TMP_FILE
done
inject ${FLAG}_START ${FLAG}_END $TMP_FILE $ACTIVE_FILE
rm $TMP_FILE


#
#CONSTRUCT ENTITY_POOL
#
ACTIVE_FILE="entity_pool.h"

FLAG="ECS_CONSTRUCT_C_INCLUDE"
touch $TMP_FILE
for i in components/*.h; do
  echo "#include \"$i\"" >> $TMP_FILE
done
inject ${FLAG}_START ${FLAG}_END $TMP_FILE $ACTIVE_FILE
rm $TMP_FILE

FLAG="ECS_CONSTRUCT_C_SIGNATURE_DEF"
touch $TMP_FILE
SIG_BIT=1
for i in components/*.h; do
  echo "const component_signature component_signature_"`fileToUnder $i`" = $SIG_BIT;" >> $TMP_FILE
  SIG_BIT=$(($SIG_BIT * 2))
done
inject ${FLAG}_START ${FLAG}_END $TMP_FILE $ACTIVE_FILE
rm $TMP_FILE

FLAG="ECS_CONSTRUCT_PUBLIC_C_DECL"
touch $TMP_FILE
for i in components/*.h; do
  UNDER=`fileToUnder $i`
  CAMEL=`underToCamel $UNDER`
  echo "$CAMEL ${UNDER}s[MAX_ENTITIES]; int num_${UNDER}s;" >> $TMP_FILE
done
inject ${FLAG}_START ${FLAG}_END $TMP_FILE $ACTIVE_FILE
rm $TMP_FILE

ACTIVE_FILE="entity_pool.cpp"

FLAG="ECS_CONSTRUCT_ZERO_COMPONENT_COUNTS"
touch $TMP_FILE
for i in components/*.h; do
  UNDER=`fileToUnder $i`
  echo "num_${UNDER}s = 0;" >> $TMP_FILE
done
inject ${FLAG}_START ${FLAG}_END $TMP_FILE $ACTIVE_FILE
rm $TMP_FILE

FLAG="ECS_CONSTRUCT_ADD_C_TO_E"
touch $TMP_FILE
for i in components/*.h; do
  UNDER=`fileToUnder $i`
  echo "if(csig & component_signature_$UNDER)"    >> $TMP_FILE
  echo "{"                                        >> $TMP_FILE
  echo "  e->$UNDER = &${UNDER}s[num_${UNDER}s];" >> $TMP_FILE
  echo "  ${UNDER}s[num_${UNDER}s].entity = e;"   >> $TMP_FILE
  echo "  num_${UNDER}s++;"                       >> $TMP_FILE
  echo "}"                                        >> $TMP_FILE
  echo ""                                         >> $TMP_FILE
done
inject ${FLAG}_START ${FLAG}_END $TMP_FILE $ACTIVE_FILE
rm $TMP_FILE

FLAG="ECS_CONSTRUCT_DELETE_C_FROM_E"
touch $TMP_FILE
for i in components/*.h; do
  UNDER=`fileToUnder $i`
  echo "if(e->${UNDER})"                                            >> $TMP_FILE
  echo "{"                                                          >> $TMP_FILE
  echo "  num_${UNDER}s--;"                                         >> $TMP_FILE
  echo "  ${UNDER}s[num_${UNDER}s].entity->${UNDER} = e->${UNDER};" >> $TMP_FILE #tell entity of last placed component where it will be moved
  echo "  *e->${UNDER} = ${UNDER}s[num_${UNDER}s];"                 >> $TMP_FILE #move final component on top of now-deleted component
  echo "}"                                                          >> $TMP_FILE
  echo ""                                                           >> $TMP_FILE
done
inject ${FLAG}_START ${FLAG}_END $TMP_FILE $ACTIVE_FILE
rm $TMP_FILE

FLAG="ECS_CONSTRUCT_DELETE_E"
touch $TMP_FILE
for i in components/*.h; do
  UNDER=`fileToUnder $i`
  echo "if(entities[num_entities].${UNDER})"            >> $TMP_FILE
  echo "  entities[num_entities].${UNDER}->entity = e;" >> $TMP_FILE
done
inject ${FLAG}_START ${FLAG}_END $TMP_FILE $ACTIVE_FILE
rm $TMP_FILE

exit 0


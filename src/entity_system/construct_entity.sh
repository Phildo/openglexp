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
  echo "std::vector<$CAMEL> ${UNDER}s;" >> $TMP_FILE
done
inject ${FLAG}_START ${FLAG}_END $TMP_FILE $ACTIVE_FILE
rm $TMP_FILE

ACTIVE_FILE="entity_pool.cpp"

FLAG="ECS_CONSTRUCT_ADD_C_TO_E"
touch $TMP_FILE
for i in components/*.h; do
  
  UNDER=`fileToUnder $i`
  CAMEL=`underToCamel $UNDER`
  echo ""                                             >> $TMP_FILE
  echo "if(csig & component_signature_$UNDER)"        >> $TMP_FILE
  echo "{"                                            >> $TMP_FILE
  echo "  $CAMEL $UNDER;"                             >> $TMP_FILE
  echo "  ${UNDER}s.push_back(std::move($UNDER));"    >> $TMP_FILE
  echo "  e.$UNDER = &${UNDER}s[${UNDER}s.size()-1];" >> $TMP_FILE
  echo "  ${UNDER}.entity = &e;"                      >> $TMP_FILE
  echo "}"                                            >> $TMP_FILE
  echo ""                                             >> $TMP_FILE
done
inject ${FLAG}_START ${FLAG}_END $TMP_FILE $ACTIVE_FILE
rm $TMP_FILE

exit 0


if [ ! -f $(dirname $0)/gbemu-lib/include/gbemu/gbemu ]; then
    echo "version.sh: error: $(dirname $0)/gbemu-lib/include/gbemu/gbemu does not exist" 1>&2
    exit 1
fi

MAJOR=`egrep '^#define +GBEMU_VERSION_MAJOR +[0-9]+$' $(dirname $0)/gbemu-lib/include/gbemu/gbemu.h`
MINOR=`egrep '^#define +GBEMU_VERSION_MINOR +[0-9]+$' $(dirname $0)/gbemu-lib/include/gbemu/gbemu.h`
PATCH=`egrep '^#define +GBEMU_VERSION_PATCH +[0-9]+$' $(dirname $0)/gbemu-lib/include/gbemu/gbemu.h`

if [ -z "$MAJOR" -o -z "$MINOR" -o -z "$PATCH" ]; then
    echo "version.sh: error: could not extract version from $(dirname $0)/gbemu-lib/include/gbemu/gbemu.h" 1>&2
    exit 1
fi

MAJOR=`echo $MAJOR | awk '{ print $3 }'`
MINOR=`echo $MINOR | awk '{ print $3 }'`
PATCH=`echo $PATCH | awk '{ print $3 }'`

echo $MAJOR.$MINOR.$PATCH | tr -d '\n'

#!/bin/bash

# =========================
#  God Perspective Script
# =========================

if [ $# -ne 1 ]; then
	echo "Usage: ./god_perspective ClassName"
	exit 1
fi

CLASS_NAME=$1
UPPER_NAME=$(echo "$CLASS_NAME" | tr '[:lower:]' '[:upper:]')
DATE=$(date +"%Y/%m/%d %H:%M:%S")
USER_NAME="jeslin-tici"
EMAIL="jeslinticianevaz@gmail.com"

HPP_FILE="${CLASS_NAME}.hpp"
CPP_FILE="${CLASS_NAME}.cpp"

# =========================
#  Create HPP
# =========================

cat > "$HPP_FILE" << EOF

#ifndef ${UPPER_NAME}_HPP
# define ${UPPER_NAME}_HPP

# include <iostream>
# include <iomanip>
# include <cmath>

class ${CLASS_NAME}
{
	public:
		${CLASS_NAME}();
		${CLASS_NAME}(const ${CLASS_NAME}& newObj);
		${CLASS_NAME}& operator=(const ${CLASS_NAME}& newObj);
		~${CLASS_NAME}();
};

#endif
EOF

# =========================
#  Create CPP
# =========================

cat > "$CPP_FILE" << EOF

#include "${CLASS_NAME}.hpp"

${CLASS_NAME}::${CLASS_NAME}()
{
	std::cout << "Default ${CLASS_NAME} constructor called" << std::endl;
}

${CLASS_NAME}::${CLASS_NAME}(const ${CLASS_NAME}& newObj)
{
	std::cout << "${CLASS_NAME} copy constructor called" << std::endl;
	*this = newObj;
}

${CLASS_NAME}& ${CLASS_NAME}::operator=(const ${CLASS_NAME}& newObj)
{
	std::cout << "${CLASS_NAME} copy assignment operator called" << std::endl;
	if (this != &newObj)
		*this = newObj;
	return (*this);
}

${CLASS_NAME}::~${CLASS_NAME}()
{
	std::cout << "${CLASS_NAME} destructor called" << std::endl;
}
EOF

echo "Created ${HPP_FILE} and ${CPP_FILE}"

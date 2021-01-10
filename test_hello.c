#include <stdio.h> 

#include "zlog.h"

int main(int argc, char** argv)
{
	int rc;
	zlog_category_t *c;
#if 0
	rc = dzlog_init("/etc/zlog.conf", "my_cat");
	if (rc) {
		printf("init failed\n");
		return -1;
	}
	dzlog_info("info, zlog:[%d]", 1);
	dzlog_debug("debug, zlog:[%d]", 2);
	dzlog_error("error, zlog:[%d]", 3);
	dzlog_warn("warn, zlog:[%d]", 4);

	zlog_fini();
	return 0;
#endif

	rc = zlog_init("/etc/zlog.conf");
	if (rc) {
		printf("init failed\n");
		return -1;
	}

	c = zlog_get_category("my_cat");
	if (!c) {
		printf("get cat fail\n");
		zlog_fini();
		return -2;
	}

	int i = 0;
//	while (1) {
	zlog_info(c, "info, zlog: [%d]", i);
/*	i++;
	zlog_debug(c, "debug, zlog: [%d]", i);
	i++;
	zlog_error(c, "error, zlog: [%d] %s", i, "zlogerror");
	i++;
	zlog_warn(c, "warn, zlog: [%d] %s", i, "zlogwarn");
*/
	//	usleep(1000);
//	}
	zlog_fini();

	return 0;
} 

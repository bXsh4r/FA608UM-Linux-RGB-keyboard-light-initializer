#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

#include <sys/ioctl.h>
#include <linux/hidraw.h>


int main(int argc, char **argv) {

	int fd;
	int res = 0;
	char buf[2];
	char *device = argv[1];

	// Open the device with read/write options
	fd = open(device, O_RDWR);
	if(fd < 0) {
		perror("Unable to open device");
		return 1;
	}

	
	memset(buf, 0x0, sizeof(buf));

	// Enable autonomous mode
	buf[0] = 0x46; // Report ID
	buf[1] = 0x01; // Boolean value true
	
	res = ioctl(fd, HIDIOCSFEATURE(2), buf);
	if(res < 0)
		perror("HIDIOCSFEATURE");
	else
		printf("ioctl HIDIOCSFEATURE returned: %d\n", res);
	
	
	close(fd);
	return 0;
}

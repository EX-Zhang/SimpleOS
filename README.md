# SimpleOS

## File tree:
	.
	├── kernel
	│   ├── boot
	│   │   └── boot.s
	│   ├── drivers
	│   │   └── console.c
	│   ├── include
	│   │   ├── common.h
	│   │   ├── console.h
	│   │   ├── string.h
	│   │   ├── types.h
	│   │   └── vargs.h
	│   ├── init
	│   │   └── kernel.c
	│   ├── libs
	│   │   ├── common.c
	│   │   └── string.c
	│   ├── makefile
	│   └── scripts
	│       └── kernel.ld
	└── README.md

7 directories, 13 files

All the files should be placed at the root of a partition. 


## How to boot
boot with grub2, add following code to the /boot/grub/grub.cfg

	menuentry 'Simple OS'{
	     insmod part_msdos
	     insmod [format of the partition]
	     set root='hd[disk num][partition num]'
	     multiboot /kernel/kEntry
	}

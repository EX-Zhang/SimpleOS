# SimpleOS

File tree:
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

boot with grub2, add following code to the /boot/grub/grub.cfg

menuentry 'Yuki OS'{
     insmod part_msdos
     insmod [format of the partition]
     set root='hd[disk num][partition num]'
     multiboot /kernel/kEntry
}

For example, my file is placed in '/dev0/sda7/*' and format is ext2
the boot code is written like this:
menuentry 'Yuki OS'{
     insmod part_msdos
     insmod ext2
     set root='hd0,7'
     multiboot /kernel/kEntry
}

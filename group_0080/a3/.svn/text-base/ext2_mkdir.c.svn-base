/*
ext2_mkdir: This program takes two command line arguments. The first is the name of an ext2 formatted virtual disk. 
The second is an absolute path on your ext2 formatted disk. The program should work like mkdir, creating the final 
directory on the specified path on the disk. If location where the final directory is to be created does 
not exist or if the specified directory already exists, then your program should return the appropriate error.
*/


/*



important operations:

free the inode of the dir
	free_inode(index of inode){
	seek to the inode bitmap which is at block 3
	read the 16 bits from the bitmap
	inode_bitmap.bits &= ~1; /*this turns the bit to zero(free)*/


}

free the data node

	free_data_bit(index of bit in data bitmap)
		seek to the data bit mapa in the image
			i.e BLOCK_SIZE*3
		read the 128 chars or bits from this location
		store them in a struct data_bitmap
		struct data_bitmap
			__64 half1;
			__g4 half2;
		if(index < 64){
			data_map.hal1 &= ~1<<index; /*sets it off*/
		} else {
			data_map.half2 &= ~1<<index;
		}

update parents directories entries




sorry i run out of time with the psudo code :(
I appologize for all the inconviniences.





*/




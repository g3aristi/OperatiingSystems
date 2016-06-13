/* ext2_rm: This program takes two command line arguments. The first is the name of an ext2 formatted virtual disk, 
and the second is an absolute path to a file or link (not a directory) on that disk. 
The program should work like rm, removing the specified file from the disk. If the file does not exist or 
if it is a directory, then your program should return the appropriate error.
*/



/* 

	parse the path to get the inode where the data of destination directory

	perfoming the folling traversal through the directory:
	
		* we know that the first parse dir, the absolute path on your ext2 formatted disk, 
		  starts at the the root, so we first check the data block of root.

		* the inode table is at block 3, and from here we get that the second inode is roots
		* reading the root_inode.inode = 7, so that tells us that the first data block of 
		  root its a t block # 7
		* we move that block #7 to read roots directory entries
		* looping through the directories entries in block 7 we find the first dir in the
		  absolute path

		* when the directory entry dir_entry.name matches the next token in the absolute path 
		  we get that location of that new directory inode index is the dir_entry.inode

		* when we extract the data from the inode.i_block[i] we get the next data block that we have to check

		* we traver the path untill we get to the end of the absolute path

		* we need to get the last dir from the absolute path inode, so that we have access to its data block
		  from which we can get the destination directory dir_entries and as well as if need it we can 
		  add new directories entries while updating the inodes._blocks pointers

		* create the new directory entry where there is space, therefore  in this block
			* find a dir_entry in bit enought
			* split the dir_entry that has enought found:
key points		check_dir_entries:
				for every entry in this block 
				check if one of them is padded
					if its padded 
						then split
					if not enought spance
						move to next entry

				split dir_entry
					over sized dir entry:
						over sized.rec_len = 8+strlen(over sized.name)

				seek to the position of the over sized dir_entry + over sized new rec_len
					create a new directory entry;
					write the new dir_entry at this possition to the ext2 fromatted virtual image
add the new dir_entry 
		create new dir entry
			new_dir_entry.inode = find a free inode
			new_dir_entry.file_type = dir  /* because we are doing mkdir*/
			new_dir_entry.rec_len =8+strlen(last directory in the path)
			new_dir_entry.name_len = strlen(last directory in the path)
			new_dir_entry.name = *last directory in the path


		find free inode
			for(i in bitmap)
				if( bitmap[i] = 0)
					return i /* which means that inode at index i in the bitmap is free */
				else 
					move on
					i ++

updata inode table 
		update inode(inode index)
			seek to the inode table 1024*3+128*index and SEEK_SET
			read this struct inode
			fread(&new_inode, 1, sizeof(struct inode), image file)
			in.i_mode = 0x8777; /* this for a file */
    in.i_size = 1024;
    in.i_links_count = 0; 
    in.i_uid = 0; /* Low 16 bits of Owner Uid */ 
    in.i_atime = 0; /* Access time */ 
    in.i_ctime = 0; /* Inode change time */ 
    in.i_mtime = 0; /* Modification time */ 
    in.i_dtime = 0; /* Deletion Time */ 
    in.i_gid = 0; /* Low 16 bits of Group Id */ 
    in.i_blocks = 6; /* Blocks count */ 
    in.i_flags = 0; /* File flags */
			

			save the index of free inode used to update inode bitmap 

		now that we have finish writing the new dir entry to the destination file its time to update every thing that
		needs to be updated


update inode bitmap
		update bitmap(index of inode now in use)
			inode bit mao.inodes |= 1<< index ;
			
		updata inode table for the nw used inode
		write to the new data block its parent and self 
		
							
*/

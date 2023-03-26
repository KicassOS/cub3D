## SOURCES.MK ##

## SRC ##

SOURCES		+=                                    		\
		src/main.c                                   	\


## SRC/ERROR_HANDLER ##

SOURCES		+=                                    		\
		src/error_handler/error_handler.c            	\
		src/error_handler/error_handler_utils.c      	\


## SRC/LST_MANAGEMENT ##

SOURCES		+=                                    		\
		src/lst_management/add_lst.c                 	\
		src/lst_management/create_lst.c              	\
		src/lst_management/init_lst.c                	\
		src/lst_management/print_lst.c               	\


## SRC/PARSING ##

SOURCES		+=                                    		\
		src/parsing/parse_node_params.c              	\
		src/parsing/get_map.c                        	\
		src/parsing/get_file_utils.c                 	\
		src/parsing/get_map_utils.c                  	\
		src/parsing/parsing_utils.c                  	\
		src/parsing/parse_rgb.c                      	\
		src/parsing/parse_requirement.params.c       	\
		src/parsing/fill_parsed_params.c             	\
		src/parsing/get_maps_utilspp.c               	\
		src/parsing/fill_params.c                    	\
		src/parsing/get_file.c                       	\


## SRC/GET_LINE ##

SOURCES		+=                                    		\
		src/get_line/get_next_line_utils.c           	\
		src/get_line/get_next_line.c                 	\


## SRC/GETTERS ##

SOURCES		+=                                    		\
		src/getters/getters_rgb_path.c               	\
		src/getters/getters_direction.c              	\


## SRC/LIB ##

SOURCES		+=                                    		\
		src/lib/ft_strnstr.c                         	\
		src/lib/ft_isdigit.c                         	\
		src/lib/ft_strncmp.c                         	\
		src/lib/ft_strlen.c                          	\
		src/lib/ft_putstr_fd.c                       	\
		src/lib/ft_strchr.c                          	\
		src/lib/ft_atoi.c                            	\
		src/lib/ft_putchar_fd.c                      	\
		src/lib/ft_strjoin.c                         	\
		src/lib/ft_split.c                           	\
		src/lib/ft_putnbr_fd.c                       	\
		src/lib/ft_strrchr.c                         	\
		src/lib/ft_striteri.c                        	\
		src/lib/ft_strdup.c                          	\


## SRC/GARBAGE_CTR ##

SOURCES		+=                                    		\
		src/garbage_ctr/garbage_collector.c          	\



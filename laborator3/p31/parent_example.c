#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <stdint.h>
#include <unistd.h>

#include <sys/wait.h>
#include <spawn.h>

char** environ;

void print_error( int e_num, char* e_msg )
{
	errno = e_num;
	perror( e_msg );
	exit( EXIT_FAILURE );
}

int main( int argc, char* argv[] )
{
	pid_t child_pid, own_pid, parent_pid;
	int f_code, child_status;
	// merg pe variantele implicite pentru semnale si fisiere
	posix_spawnattr_t* ptr_attr = NULL;
	posix_spawn_file_actions_t* ptr_file_actions = NULL;

	if( 3 > argc )
	{
		printf( "%s -c|-p sys-command|program-name [command args for program-name]\n", argv[0] );
		return 0;
	}

	own_pid = getpid( );
	parent_pid = getppid( );

	printf( "Parent process started with pid %jd/parent %jd\n", (intmax_t) own_pid, (intmax_t) parent_pid );

	// no argument validation !!!
	switch( argv[1][1] )
	{
		case 'c':
			printf( "Attempt to spawn new process for command \"%s\"...\n", argv[2] );
			f_code = posix_spawnp( &child_pid, argv[2], ptr_file_actions, ptr_attr, &argv[2], environ );
			if( 0 != f_code )
			{
				print_error( f_code, "posix_spawnp" );
			}
			printf( "New process created successfully for \"%s\" - PID: %jd\n", argv[2], (intmax_t) child_pid );
			break;
		case 'p':
			printf( "Attempt to spawn new process for program \"%s\"...\n", argv[2] );
			f_code = posix_spawnp( &child_pid, argv[2], ptr_file_actions, ptr_attr, &argv[2], environ );
			if( 0 != f_code )
			{
				print_error( f_code, "posix_spawn" );
			}
			printf( "New process created successfully for \"%s\" - PID: %jd\n", argv[2], (intmax_t) child_pid );
			break;
	}

	do
	{
		f_code = waitpid( child_pid, &child_status, WUNTRACED | WCONTINUED );
		if( -1 == f_code )
		{
			print_error( f_code, "waitpid" );
		}
		printf( "Child status: " );
		if( WIFEXITED( child_status ) )
		{
			printf( "finished, exit code: %d\n", WEXITSTATUS( child_status ) );
		}
		else
		{
			if( WIFSIGNALED( child_status ) )
			{
				printf( "killed by signal %d\n", WTERMSIG( child_status ) );
			}
			else
			{
				if( WIFSTOPPED( child_status ) )
				{
					printf( "stopped by signal %d\n", WSTOPSIG( child_status ) );
				}
				else
				{
					if( WIFCONTINUED( child_status ) )
					{
						printf( "running\n" );
					}
				}
			}
		}
	} while( 0 == WIFEXITED( child_status ) && 0 == WIFSIGNALED( child_status ) );

	return 0;
}

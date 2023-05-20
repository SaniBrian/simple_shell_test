#include "shell.h"

/**
*path_finder - find executables paths
*@exe: executable name
*Return: NULL if not found and the path if found
*/

char *path_finder(char *exe)
{
	char *path_env = NULL, *token, *test_path = NULL;

	path_env = _strdup(getenv("PATH"));
	if (path_env == NULL)
		return (NULL);
	token = _strtok(path_env, ":\n");
	while (token != NULL)
	{
		test_path = append_path(token, exe);
		if (test_path == NULL)
		{
			free(path_env);
			return (NULL);
		}
		if (access(test_path, F_OK | X_OK) == 0)
		{
			free(path_env);
			return (test_path);
		}
		free(test_path);
		test_path = NULL;
		token = _strtok(NULL, ":\n");
	}
	free(path_env);
	return (NULL);
}

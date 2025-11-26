#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief pointer to the function addres provider of the library used for
 * managing hardware (SDL, glfw, ...)
 */
void *get_gl_proc_addr(const char *name);


#ifdef __cplusplus
}
#endif

find_program(POLICY_TS_CONV deepin-policy-ts-convert REQUIRED)
add_custom_target(APP_POLICY_FILE
    ALL
    COMMAND ${POLICY_TS_CONV} ts2policy ${CMAKE_CURRENT_SOURCE_DIR}/${POLICY_FILE} ${CMAKE_CURRENT_SOURCE_DIR}/ ${POLICY_FILE}.tmp
    COMMAND mv ${POLICY_FILE}.tmp ${POLICY_FILE}
)
install(FILES ${POLICY_FILE} DESTINATION share/polkit-1/actions)

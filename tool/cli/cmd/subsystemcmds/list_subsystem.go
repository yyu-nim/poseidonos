package subsystemcmds

import (
	"encoding/json"

	"cli/cmd/displaymgr"
	"cli/cmd/globals"
	"cli/cmd/messages"
	"cli/cmd/socketmgr"

	"github.com/labstack/gommon/log"
	"github.com/spf13/cobra"
)

var ListSubsystemCmd = &cobra.Command{
	Use:   "list",
	Short: "Get a list of subsystems from PoseidonOS.",
	Long: `Get a list of subsystems from PoseidonOS.

Syntax:
	poseidonos-cli subsystem list [(--subnqn | -q) SubsystemNQN]

	Example:
	poseidonos-cli subsystem list --subnqn nqn.2019-04.pos:subsystem
    `,
	Run: func(cmd *cobra.Command, args []string) {

		var command = "LISTSUBSYSTEM"

		listSubsystemParam := messages.ListSubsystemParam{
			SUBNQN: list_subsystem_subnqn,
		}

		ListSubsystemReq := messages.Request{
			RID:     "fromCLI",
			COMMAND: command,
			PARAM:   listSubsystemParam,
		}

		reqJSON, err := json.Marshal(ListSubsystemReq)
		if err != nil {
			log.Debug("error:", err)
		}

		displaymgr.PrintRequest(string(reqJSON))

		// Do not send request to server and print response when testing request build.
		if !(globals.IsTestingReqBld) {
			socketmgr.Connect()

			resJSON, err := socketmgr.SendReqAndReceiveRes(string(reqJSON))
			if err != nil {
				log.Debug("error:", err)
				return
			}

			socketmgr.Close()

			displaymgr.PrintResponse(command, resJSON, globals.IsDebug, globals.IsJSONRes)
		}
	},
}

// Note (mj): In Go-lang, variables are shared among files in a package.
// To remove conflicts between variables in different files of the same package,
// we use the following naming rule: filename_variablename. We can replace this if there is a better way.
var list_subsystem_subnqn = ""

func init() {
	ListSubsystemCmd.Flags().StringVarP(&list_subsystem_subnqn, "subnqn", "q", "", "NQN of the subsystem to list spec")
}

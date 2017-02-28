#include "midi.h"
#include "instruction.h"

void lash_netsimmidiInstructionReset(lash_netsimmidi_instruction_t *ins) {
	ins->state = LASH_NETSIMMIDI_NEW;
	ins->one = -1;
	ins->other = -1;
	memset(ins->result, 0, 3);
}

int lash_netsimmidiInstructionTranslate(lash_netsimmidi_instruction_t *ins, lash_netsimmidi_input_status_t *st) {
	switch (st->instruction) {
		case LASH_NETSIMMIDI_NOTEON:
			ins->state = LASH_NETSIMMIDI_PENDING;
			ins->one = st->key;
			ins->result[0] = LASH_NETSIMMIDI_NODE;
			ins->result[1] = st->key;
			break;
		case LASH_NETSIMMIDI_NOTEOFF:
			ins->state = LASH_NETSIMMIDI_COMPLETED;
			ins->result[0] = LASH_NETSIMMIDI_NODE;
			ins->result[1] = st->key;
			break;
		case LASH_NETSIMMIDI_CTRLCHANGE:
			ins->state = LASH_NETSIMMIDI_COMPLETED;
			ins->result[0] = LASH_NETSIMMIDI_DIAL;
			ins->result[1] = st->key;
			ins->result[2] = st->value;
			break;
		default:
			return -1;
	}
	return 0;
}

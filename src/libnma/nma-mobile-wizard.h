/* NetworkManager Connection editor -- Connection editor for NetworkManager
 *
 * Dan Williams <dcbw@redhat.com>
 * Lubomir Rintel <lkundrak@v3.sk>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 *
 * (C) Copyright 2008 - 2018 Red Hat, Inc.
 */

#ifndef MOBILE_WIZARD_H
#define MOBILE_WIZARD_H

#include <glib.h>
#include <NetworkManager.h>
#include <nm-device.h>

typedef struct _NMAMobileWizard NMAMobileWizard;
typedef struct _NMAMobileWizardClass NMAMobileWizardClass;

/**
 * NMAMobileWizardAccessMethod:
 * @provider_name: The mobile network provider name
 * @plan_name: The provided network access billing plan
 * @devtype: Required NetworkManager device capabilities
 * @username: User login
 * @password: User secret
 * @gsm_apn: The GSM Access Point Name
 *
 * Network access method details.
 */
typedef struct {
	char *provider_name;
	char *plan_name;
	NMDeviceModemCapabilities devtype;
	char *username;
	char *password;
	char *gsm_apn;
} NMAMobileWizardAccessMethod;

typedef void (*NMAMobileWizardCallback) (NMAMobileWizard *self,
                                         gboolean canceled,
                                         NMAMobileWizardAccessMethod *method,
                                         gpointer user_data);

#define NMA_TYPE_MOBILE_WIZARD            (nma_mobile_wizard_get_type ())
#define NMA_MOBILE_WIZARD(obj)            (G_TYPE_CHECK_INSTANCE_CAST ((obj), NMA_TYPE_MOBILE_WIZARD, NMAMobileWizard))
#define NMA_MOBILE_WIZARD_CLASS(klass)    (G_TYPE_CHECK_CLASS_CAST ((klass), NMA_TYPE_MOBILE_WIZARD, NMAMobileWizardClass))
#define NMA_IS_MOBILE_WIZARD(obj)         (G_TYPE_CHECK_INSTANCE_TYPE ((obj), NMA_TYPE_MOBILE_WIZARD))
#define NMA_IS_MOBILE_WIZARD_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), NMA_TYPE_MOBILE_WIZARD))
#define NMA_MOBILE_WIZARD_GET_CLASS(obj)  (G_TYPE_INSTANCE_GET_CLASS ((obj), NMA_TYPE_MOBILE_WIZARD, NMAMobileWizardClass))

GType nma_mobile_wizard_get_type (void);

NMAMobileWizard *nma_mobile_wizard_new (GtkWindow *parent,
                                        GtkWindowGroup *window_group,
                                        NMDeviceModemCapabilities modem_caps,
                                        gboolean will_connect_after,
                                        NMAMobileWizardCallback cb,
                                        gpointer user_data);

void nma_mobile_wizard_present (NMAMobileWizard *wizard);

void nma_mobile_wizard_destroy (NMAMobileWizard *self);

#endif /* MOBILE_WIZARD_H */

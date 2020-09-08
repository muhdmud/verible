// Copyright 2017-2020 The Verible Authors.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//      http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include "verilog/analysis/checkers/declared_identifier_style_rule.h"

#include <set>
#include <string>

#include "absl/strings/match.h"
#include "absl/strings/str_cat.h"
#include "common/analysis/citation.h"
#include "common/analysis/lint_rule_status.h"
#include "common/analysis/matcher/bound_symbol_manager.h"
#include "common/strings/naming_utils.h"
#include "common/text/symbol.h"
#include "common/text/syntax_tree_context.h"
#include "verilog/analysis/lint_rule_registry.h"
#include "verilog/CST/module.h"
#include "verilog/CST/functions.h"

namespace verilog {
namespace analysis {

VERILOG_REGISTER_LINT_RULE(DeclaredIdentifierStyleRule);

using verible::GetStyleGuideCitation;
using verible::LintRuleStatus;
using verible::LintViolation;
using verible::SyntaxTreeContext;


absl::string_view DeclaredIdentifierStyleRule::Name() { return "declared-identifiers-style"; }
const char DeclaredIdentifierStyleRule::kTopic[] = "identifiers";
const char DeclaredIdentifierStyleRule::kMessage[] =
    "Check declared identifiers";

std::string DeclaredIdentifierStyleRule::GetDescription(
    DescriptionType description_type) {
  return absl::StrCat("Checks for"
                      " declared identifiers against set of unwanted patterns"
                      " See ",
                      GetStyleGuideCitation(kTopic), ".");
}

void DeclaredIdentifierStyleRule::Visit(const verible::SyntaxTreeNode& node) {
    const auto tag = static_cast<verilog::NodeEnum>(node.Tag().tag);
    switch(tag) {

        case NodeEnum::kModuleDeclaration: {
            //auto module_match = GetModuleNameToken(node);
            //absl::string_view module_id = module_match.text();
            break;
        }
        case NodeEnum::kFunctionDeclaration: {
            //auto func_match = GetFunctionId(node);
            break;
        }
        default:
        break;
    }
}

LintRuleStatus DeclaredIdentifierStyleRule::Report() const {
  return LintRuleStatus(violations_, Name(), GetStyleGuideCitation(kTopic));
}

}  // namespace analysis
}  // namespace verilog

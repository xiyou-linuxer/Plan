import { useMDXComponents as getThemeComponents } from 'nextra-theme-docs'
import { Callout } from 'nextra/components'

const themeComponents = getThemeComponents()

export function useMDXComponents(components?: Record<string, React.ComponentType>) {
  return {
    Callout,
    ...themeComponents,
    ...components,
  }
}
